"""
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine-Marie Lirazan
Homework: 08 Python Class
"""

import math
import numpy as np

# Problem 1

print("Problem #1")

class Point:
    # Requirement: Constructor sets self.x and self.y with defaults 0, 0
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    # Requirement: __str__ must print the point as (x,y)
    def __str__(self):
        return f"This point is ({self.x},{self.y})"

    # Requirement: Overload subtraction (-) to compute distance between two points
    def __sub__(self, other):
        return math.sqrt((self.x - other.x)**2 + (self.y - other.y)**2) 


# Requirement: Test code must print two points and their distance
p1 = Point()
p2 = Point(5, 7)
print(p1)
print(p2)
distance = p1 - p2
print("The distance from p1 to p2 is", distance)
print()

# Problem 2

print("Problem #2")

class myMat:
    # Requirement: Constructor creates rows × columns zero matrix
    def __init__(self, rows=0, cols=0):
        self.mat = np.zeros((rows, cols))

    # Requirement: addValue must expand matrix size and insert/overwrite value
    def addValue(self, row, col, value):
        if row >= self.mat.shape[0] or col >= self.mat.shape[1]:
            new_rows = max(row + 1, self.mat.shape[0])
            new_cols = max(col + 1, self.mat.shape[1])
            new_mat = np.zeros((new_rows, new_cols))
            new_mat[:self.mat.shape[0], :self.mat.shape[1]] = self.mat
            self.mat = new_mat

        self.mat[row, col] = value

    # Requirement: Overload * operator to multiply using numpy.dot
    def __mul__(self, rhs):
        return np.dot(self.mat, rhs.mat)

    # Requirement: Overload __str__ to print matrix contents
    def __str__(self):
        return str(self.mat)


# Requirement: Test script for matrix creation and multiplication
x = myMat()
print(x)
print()

x.addValue(1,1,6)
print(x)
print()

x.addValue(2,2,5)
x.addValue(1,0,4)
x.addValue(0,1,3)
x.addValue(2,0,20)
x.addValue(2,0,2)
print(x)
print()

y = myMat(3,3)
print(y)
print()

y.addValue(0,0,2)
y.addValue(0,1,3)
y.addValue(0,2,4)
y.addValue(1,0,5)
y.addValue(1,2,6)
y.addValue(2,1,7)
y.addValue(2,2,8)
print(y)
print()

print(x * y)
print()