#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 20 04:52:49 2018

@author: achmadi
"""

from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg
import sys

import time
from ThorlabsPM100 import ThorlabsPM100, USBTMC

class Plot2D():
    def __init__(self):
        self.traces = dict()

        self.app = QtGui.QApplication([])

        pg.setConfigOption('background', 'w')
        pg.setConfigOption('foreground', 'k')        
        pg.setConfigOptions(antialias=True)

        self.win = pg.GraphicsWindow(title="Basic OPM plotting")
        self.win.resize(1000,600)
        self.win.setWindowTitle('Category: Safe')        

        self.canvas = self.win.addPlot(title="Wavelength: 1550nm")

    def start(self):
        if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
            QtGui.QApplication.instance().exec_()

    def trace(self,name,dataset_x,dataset_y):
        if name in self.traces:
            self.traces[name].setData(dataset_x,dataset_y,pen={'color':'k','width':2})
        else:
            self.traces[name] = self.canvas.plot(pen='y')

if __name__ == '__main__':

    inst = USBTMC(device="/dev/usbtmc0")
    opm = ThorlabsPM100(inst=inst)

    opm.sense.correction.wavelength=1550
    time.sleep(0.5)

#    print(opm.sense.correction.wavelength)
#    time.sleep(1)

    opm.sense.power.dc.unit="W"
    time.sleep(0.5)

#    print(opm.sense.power.dc.unit)
#    time.sleep(1)

    p = Plot2D()
    x = np.arange(0,100,1)
    y = np.zeros(100)

    def update():
        global p, x, y
        y = np.roll(y,1,axis=0)
        y[0] = opm.read
        p.trace("data",x,y)

    timer = QtCore.QTimer()
    timer.timeout.connect(update)
    timer.start(100)

    p.start()
