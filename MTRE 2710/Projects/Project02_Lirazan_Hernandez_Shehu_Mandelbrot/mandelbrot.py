# Class: MTRE 2710
# Section: 01
# Term: Fall 2025
# Instructor: Dr. Meiling Sha
# Name: Christine Marie Lirazan
# Group: Julian Hernandez, Hadassah Shehu
# Final Project: Displaying Fractals from the Mandelbrot Set

import numpy as np
import os
import matplotlib.pyplot as plt

# Requirement: Define initial real and imaginary domain bounds
xmin=-1.5
xmax=0.5
ymin=-1.2
ymax=1.2
domain = [xmin,xmax,ymin,ymax]

# Requirement: Save domain to file so C++ can read it
np.savetxt('domain.txt',domain)

# Requirement: Execute the C++ Mandelbrot program to generate nFile
os.system("Mandelbrot.exe")

# Requirement: Load n values from C++ output file
data = np.loadtxt('nfile.txt')

# Requirement: Optionally transform n for better color contrast (log scaling)
n = np.log(np.log(data+1))

# Requirement: Compute domain size for plotting aspect ratio
dR = domain[1]-domain[0]
dI = domain[3]-domain[2]

# Requirement: Display Mandelbrot image
plt.figure(1)
plt.clf()
plt.imshow(n)
plt.gca().set_aspect(dI/dR)
plt.pause(0.001)

# Requirement: Allow user to select new region with mouse clicks (ginput)
p = plt.ginput(2)
p = np.array(p)

# Requirement: Map clicked pixel positions to new real/imag domain values
domain = [min(p[:,0]*dR/(n.shape[1]-1)+domain[0]),
          max(p[:,0]*dR/(n.shape[1]-1)+domain[0]),
          min(p[:,1]*dI/(n.shape[0]-1)+domain[2]),
          max(p[:,1]*dI/(n.shape[0]-1)+domain[2])]
   


    
    
    