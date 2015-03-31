#!/usr/bin/env python

import sys
from mpl_toolkits.mplot3d import Axes3D
import numpy
import matplotlib.pyplot as plt

data = numpy.loadtxt(sys.argv[1])
print data
fig = plt.figure()
ax = fig.gca()
ax.plot(data[:,0], data[:,1], '.-')
plt.show()
