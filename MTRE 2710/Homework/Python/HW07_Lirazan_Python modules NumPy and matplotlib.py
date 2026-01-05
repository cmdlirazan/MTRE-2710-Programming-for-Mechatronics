"""
Class: MTRE 2710
Section: 01
Term: Fall 2025
Instructor: Dr. Meiling Sha
Name: Christine-Marie Lirazan
Homework: 07 Python modules NumPy and matplotlib
"""

import matplotlib.pyplot as plot
import numpy as np

# Probelm 1

print("Problem 1")
print("See Figure 1")

# Requirement: Load the data in HW07data.txt which represents measured distances (in.) and forces (lbf).
data = np.loadtxt('HW06data.txt')

# Requirement: The file consists of a single column of values where the first half are x and the second half are F values.
x = data[0:int(len(data)/2) ]
F = data[  int(len(data)/2):]

# Requirement: Initialize variables to ensure the loop starts.
m    = 0
rOld = 0
r = 0.01

# Requirement: Add dummy element to take away in loop.
x = np.hstack((x,0))
F = np.hstack((F,0))

# Requirement: Create a loop to recalculate the optimal slope when removing the last data point.
# Requirement: Continue to remove data points until the correlation coefficient stops increasing.
while r > rOld:
    rOld = r    
    mOld = m  
    
    # Requirement: Eliminate one data point each iteration.
    x = x[0:-1] 
    F = F[0:-1]
    
    # Requirement: Calculate slope when intercept b = 0.
    m = sum(x*F)/sum(x*x)
    
    # Requirement: Calculate the sum squared error for a linear curve fit.
    Sr = sum((F - m*x       )**2)
    St = sum((F - np.mean(F))**2)
    
    # Requirement: Calculate the correlation coefficient.
    r = np.sqrt(1-Sr/St)

# Requirement: When r stops increasing, revert to the previous best slope.
m = mOld

# Requirement: Reload the complete data for plotting.
x = data[0:int(len(data)/2) ]
F = data[  int(len(data)/2):]

# Requirement: Display the resulting spring constant k, with appropriate units, for the linear region.
plot.figure(1)
plot.clf
plot.plot(x,F,'b*',label='Original data')
plot.plot([0,np.max(x)],[0,m*np.max(x)],'g-',label='Best fit')
plot.xlabel('Distance (in.)')
plot.ylabel('Force (lbf)')
plot.legend()

print('k = ', np.round(m,1) , ' lbf/in.');

print()

# Problem 2

print("Problem 2")
print("See Figure 2")
# Requirement: Use the equation ΔP = f(L/D)(ρv²/2) for the pressure drop in a pipe.
# Requirement: The friction factor f depends implicitly on viscosity μ and must be solved iteratively.

# Requirement: Use constants from Table 1 for liquid water flowing through a pipe.
L = 1                     # (m) Pipe length
D = 0.05                  # (m) Pipe diameter
rho = 884.1               # (kg/m³) Density
mu = 0.486                # (N·s/m²) Viscosity

# Requirement: Plot the pressure drop for speeds ranging between 50 and 100 m/s.
v = np.linspace(50, 100, 50) 
f = np.zeros_like(v)

# Requirement: Write a while loop which continually recalculates f from a 0.01 starting value.
for n in range(len(v)):   
    f[n] = 0.01
    while True:             
        fNew = (0.5 / np.log10(2.51 * mu/ ( rho * D * v[n] * np.sqrt(f[n]))))**2;
        # Requirement: Continue loop until subsequent recalculations for f do not change significantly.
        if abs(fNew - f[n]) < 1e-6:
            break
        f[n] = fNew;  

# Requirement: Compute the pressure drop (ΔP) for each flow speed and convert to MPa.
dp = f * (L / D) * (rho * v**2 / 2) /1e6; 

# Requirement: Plot the pressure drop for speeds ranging between 50 and 100 m/s using the values in Table 1.
plot.figure(2)
plot.clf
plot.plot(v,dp)
plot.xlabel('Flow speed (m/s)')
plot.ylabel('Pressure drop over 1 m of pipe (MPa)')

print()

# Problem 3

print("Problem 3")
print("See Figure 3")

# Requirement: Generate a surface plot of the function z = x e^(-x^2 - y^2).
# Requirement: The inequality x² + y² ≤ 4 and y ≥ 0 defines the domain inside the semicircle of radius 2.

# Requirement: Use the NumPy functions linspace and meshgrid to define the domain.
x = np.linspace(-2, 2, 200)
x,y = np.meshgrid(np.linspace(-5,5,300),np.linspace(0,3,300))

# Requirement: Compute z for positions inside the semicircle of radius 2 centered at the origin.
z = np.sin(x)*np.cos(y)
z[y**2 < 4-x**2] = np.nan # Requirement: Apply the inequality x² + y² ≤ 4 to mask values outside the semicircle.

fig = plot.figure(3)
plot.clf()
ax = fig.add_subplot(projection='3d')
ax.plot_surface(x,y,z)
ax.set_xlim(-5,5)
ax.set_ylim( 0,3)
ax.set_zlim(-1,1)


# Requirement: Display all figures.
plot.show()



