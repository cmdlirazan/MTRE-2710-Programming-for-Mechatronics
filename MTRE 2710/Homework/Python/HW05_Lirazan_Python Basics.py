"""
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine-Marie Lirazan
Homework: 05 Python Basics 
"""

import numpy as np
import random


# Problem 1

print("Problem 1")

# Requirement: Use while loop to find number of positive integers where i^2.5 < 1,000,000
i = 1
while i**2.5 < 1e6:
    i += 1

# Requirement: Display results
print(f"{i} ** 2.5 is {i**2.5}, greater than 1,000,000!")
print(f"{i-1} ** 2.5 = {(i-1)**2.5}, which is less than 1,000,000!")
print(f"There are {i-1} positive integers for which i ** 2.5 < 1,000,000.")
print()


# Problem 2

print("Problem 2")

# Requirement: Create a 4x4 matrix containing random integers (3-12)
mat = np.random.randint(3,13,(4,4)) 

# Requirement: Display matrix and its sum.
print("The original matrix: ")
print(mat)
print('Sum of elements is: ',np.sum(mat))

# Requirement: Replace center 2×2 matrix with zeros.
mat[1:3,1:3] = 0

# Requirement: Display modified 4×4 matrix.
print("The modified matrix: ")
print(mat)

print()


# Problem 3

print('Problem 3')

# Requirement: Create a 5x5 array of ones
Arr1 = np.ones((5,5))

# Requirement: Replace the center 3x3 block with zeros
Arr1[1:4,1:4]=0

# Requirement: Set the center element to 9
Arr1[2,2] = 9

# Requirement: Display the array
print(Arr1)

# Requirement: Find and print indices of all zeros
bool_indx = np.where(Arr1 == 0)
print(bool_indx)

# Requirement: Find and print the maximum value
Arr1_max = np.max(Arr1)
print('The maximum is',Arr1_max)

print()


# Problem 4

print('Problem 4')

# Requirement: Create list of 10 random integers (1-20)
i = 0
l1 =[]
while i < 10:
    r_num = random.randint(0,21)
    l1.append(r_num)
    i += 1
    
# Requirement: Save numbers to a text file
np.savetxt("List.txt", l1)

# Requirement: Import numbers back into a list (or array)
with open('List.txt', 'r') as file:
    num = []
    for line in file:
        x = float(line.strip())
        num.append(x) 

# Requirement: Display the array
print(num)

# Requirement: Find and display the sum of the array
print('The sum of the array is', sum(num))

# Requirement: Display the last two elements using slicing
print('The last two items are:', num[-2:])
print()

#Problem 5

print("Problem 5")

# Requirement: Approximate the value of π using random sampling in a quarter unit circle
maxIter = 500000
count = 0

# Requirement: Generate random (x, y) points and count how many fall inside the quarter circle
for i in range(maxIter):
    x = np.random.random()
    y = np.random.random()
    if x**2 + y**2 < 1:
        count += 1
        
# Requirement: Estimate π using ratio of points inside the circle
pi = 4*count/maxIter

# Requirement: Display the approximate value of π
print("π ≈ ",pi)