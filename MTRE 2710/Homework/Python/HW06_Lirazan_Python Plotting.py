"""
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine-Marie Lirazan
Homework: 06 Python Plotting
"""

import numpy as np
import matplotlib.pyplot as plot

# Problem 1

print("Problem 1")
print("See Figure 1")

# Requirement: Plot the function on the domain [0, 2π] using enough points for a smooth line.
x = np.linspace(0,2.000*np.pi, 500)

# Requirement: Add markers at intervals of π/8.
xMark = np.arange(0, 2.001*np.pi, np.pi/8)

y  = 2*np.sin(x) - 3*np.cos(2*x)
yMark = 2*np.sin(xMark) - 3*np.cos(2*xMark)

plot.figure(1)
plot.clf()

# Requirement: Format the plot so that the line is black with a linewidth of 4.
plot.plot(x,y, 'k-', linewidth=4)

# Requirement: Use black triangular markers of size 15.
plot.plot(xMark, yMark, 'k^', markersize=15)

# Requiremenr: Adjust the axis to fit the domain and range exactly.
plot.axis((0, 2*np.pi, min(y), max(y)))

# Display the x positions where the two peaks appear 
print("Peaks at x-values of: ")
print(x[np.where(np.logical_and(y[2:] < y[1:-1], y[1:-1] > y[:-2]))])
for i in range(0, len(y)-2):
    if y[i+1]>y[i] and y[i+2]<y[i+1]:
        print(x[i])
print()

# Problem 2

print("Problem 2")
print("See Figure 2")
M = 120
Mz = -M*np.sqrt(2)/2
My = -M*np.sqrt(2)/2
Iz = 736e-8
Iy = 1584e-8

# Requiremenr: Use np.meshgrid to define the domain.
z,y = np.meshgrid(np.arange(0.05,-0.05,-0.0005),
                  np.arange(0.08,-0.08,-0.0005))

# Requirement: Remove the area inside the channel by detecting the hole.
badInd = np.logical_and(abs(y)<0.07, abs(z)<0.04)
z[badInd] = np.nan
y[badInd] = np.nan

# Requirement: Compute the normal stress due to the bending moment M.
sigma = -Mz*y/Iz + My*z/Iy

# Requirement: Use figsize to match horizontal and vertical scales.
plot.figure(2, figsize=(10,16))
plot.clf()
ax = plot.axes(projection='3d')
ax.plot_surface(z*100,y*100,sigma/1e6)

# Requiremnt: Label axes and include units.
ax.set_xlabel("Horizontal position (cm)")
ax.set_xlabel("Vertical position (cm)")
ax.set_xlabel("Stress (MPa)")
