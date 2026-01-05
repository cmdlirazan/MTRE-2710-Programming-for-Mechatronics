/*
Class: MTRE 2710L
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine Marie Lirazan
Group: Julian Hernandez, Hadassah Shehu
Lab: 03 Controlling Motor Motion
*/

bool rotEncState, rotEncIntrptState, limitState, partDetect;

int mode, colorData;

unsigned long startTime, intrptTime, delta;

int rotaryEncoder = 2, motorDirA = 3, motorDirB = 4, limitswitch = 7, motorPin = 9;
int solenoidArm = 10, solenoidSuction = 11, photoTransitor = 12, photoSensor = A0;

// Requirement 4: Adjustable encoder click values for each sorted bin
int RED = 5, BLUE = 6, WHITE = 7;

int val = 200;

// Requirement 1: Encoder edge count updated using interrupt
volatile int count;

void setup() {

  Serial.begin(9600);

  pinMode(rotaryEncoder, INPUT);
  pinMode(limitswitch, INPUT);
  pinMode(photoSensor, INPUT);
  pinMode(photoTransitor, INPUT);

  pinMode(motorPin, OUTPUT);
  pinMode(motorDirA, OUTPUT);
  pinMode(motorDirB, OUTPUT);
  pinMode(solenoidArm, OUTPUT);
  pinMode(solenoidSuction, OUTPUT);

  rotEncState = HIGH;
  startTime = micros();
  mode = 0;
  count = 0;

  analogWrite(motorPin, val);

// Requirement 1: Interrupt used to count encoder edges for arm rotation
  attachInterrupt(0, encoderInterrupt, CHANGE);
}

// Requirement 1: Interrupt Service Routine counts encoder edges to track arm rotation
void encoderInterrupt() {

  rotEncIntrptState = digitalRead(rotaryEncoder);
  intrptTime = micros();
  delta = intrptTime - startTime;

  if (rotEncIntrptState == LOW && rotEncState == HIGH && delta > 150000) {
    count++;
    startTime = micros();
  }

  rotEncState = rotEncIntrptState;
}

void loop() {

  // Requirement 3: Mode 0 = Homing mode
  if (mode == 0) {

    limitState = digitalRead(limitswitch);

    // Requirement 2: Rotate counter-clockwise until limit switch is pressed
    if (limitState == HIGH) {
      digitalWrite(motorDirA, LOW);
      digitalWrite(motorDirB, LOW);
      delay(2000);
      count = 0;
      mode = 1;
    } else {
      digitalWrite(motorDirA, LOW);
      digitalWrite(motorDirB, HIGH);
    }
  }

  // Requirement 3: Mode 1 = Detect part and prepare to travel to color sensor
  if (mode == 1) {
    partDetect = digitalRead(photoTransitor);

    if (partDetect == HIGH) {
      digitalWrite(solenoidArm, HIGH);
      digitalWrite(solenoidSuction, HIGH);
      delay(2000);
      digitalWrite(solenoidArm, LOW);
      delay(2000);
      mode = 2;
    }
  }

  // Requirement 3: Mode 2 = Travel to color sensor using encoder counts
  if (mode == 2) {
    digitalWrite(motorDirA, HIGH);
    digitalWrite(motorDirB, LOW);

    if (count == 4) {
      digitalWrite(motorDirA, LOW);
      digitalWrite(motorDirB, LOW);
      delay(1000);
      digitalWrite(solenoidArm, HIGH);
      delay(2000);
      colorData = analogRead(photoSensor);
      delay(2000);
      digitalWrite(solenoidArm, LOW);
      mode = 3;
    }
  }

  // Requirement 4: Mode 3 selects sorted bin based on color sensor
  if (mode == 3) {
    if (colorData > 510 && colorData < 580) {
      mode = 4;
    } else if (colorData > 581 && colorData < 610) {
      mode = 5;
    } else if (colorData > 610) {
      mode = 6;
    } else {
      mode = 7;
    }
  }

  // Requirement 4: Mode 4 = Move to WHITE bin using adjustable encoder value
  if (mode == 4) {
    digitalWrite(motorDirA, HIGH);
    digitalWrite(motorDirB, LOW);

    if (count == WHITE) {
      digitalWrite(motorDirA, LOW);
      digitalWrite(motorDirB, LOW);
      delay(2000);
      digitalWrite(solenoidArm, HIGH);
      delay(1000);
      digitalWrite(solenoidSuction, LOW);
      delay(1000);
      digitalWrite(solenoidArm, LOW);
      delay(1000);
      mode = 0;
    }
  }

  // Requirement 4: Mode 5 = Move to RED bin using adjustable encoder value
  if (mode == 5) {
    digitalWrite(motorDirA, HIGH);
    digitalWrite(motorDirB, LOW);

    if (count == RED) {
      digitalWrite(motorDirA, LOW);
      digitalWrite(motorDirB, LOW);
      delay(2000);
      digitalWrite(solenoidArm, HIGH);
      delay(1000);
      digitalWrite(solenoidSuction, LOW);
      delay(1000);
      digitalWrite(solenoidArm, LOW);
      delay(1000);
      mode = 0;
    }
  }

  // Requirement 4: Mode 6 = Move to BLUE bin using adjustable encoder value */
  if (mode == 6) {
    digitalWrite(motorDirA, HIGH);
    digitalWrite(motorDirB, LOW);

    if (count == BLUE) {
      digitalWrite(motorDirA, LOW);
      digitalWrite(motorDirB, LOW);
      delay(2000);
      digitalWrite(solenoidArm, HIGH);
      delay(1000);
      digitalWrite(solenoidSuction, LOW);
      delay(1000);
      digitalWrite(solenoidArm, LOW);
      delay(1000);
      mode = 0;
    }
  }

  /* Requirement 4: Mode 7 = Re-read color if sensor value is unclear */
  if (mode == 7) {
    digitalWrite(solenoidArm, HIGH);
    delay(2000);
    colorData = analogRead(photoSensor);
    delay(2000);
    digitalWrite(solenoidArm, LOW);
    mode = 3;
  }
}
