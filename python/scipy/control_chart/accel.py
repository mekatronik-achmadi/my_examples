#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 12 06:58:25 2017

@author: achmadi
"""

# import modules
import numpy as np

from my_controlchart import MyControlChart

cch = MyControlChart()

# load CSV
loadcsv = np.genfromtxt('data_acc.csv', delimiter=',')
datacsv = loadcsv[:,1]

kons = 3

ucl = cch.shewart_ucl(datacsv,kons)
lcl = cch.shewart_lcl(datacsv,kons)
cch.plot_shewart(datacsv,kons)