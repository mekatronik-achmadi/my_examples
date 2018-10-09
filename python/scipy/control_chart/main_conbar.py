#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 12 21:01:23 2017

@author: achmadi

pusing bro, ada obat nyamuk?
"""

# import modules
import scipy.io as sio
from my_controlchart import MyControlChart

cch = MyControlChart()

# load data
loadedmat = sio.loadmat('engine_data.mat')
datainput = loadedmat['engine_AFR']

ngroup = 30

# data grouping
#dat_group = cch.grouping(datainput,5)

# data parameter
#dat_mean = cch.mean(datainput)
#dat_stddev = cch.stddev(datainput)
#dat_smpavg = cch.sample_avg(datainput,5)
#v_cl = cch.data_cl(datainput)
#v_ucl = cch.data_ucl(datainput,5)
#v_lcl = cch.data_lcl(datainput,5)

# data parameter using mean of mean
#dat_mean_group = cch.mean_mean(datainput,5)
#dat_stddev_mean = cch.stddev_meanmean(datainput,5)

# plot control chart
#stdgrup = cch.stddev_group(datainput,ngroup)
#meangrp = cch.mean_group(datainput,ngroup)
#rangegrp = cch.data_range_group(datainput,ngroup)
#meanrangegrp = cch.data_mean_range(datainput,ngroup)
#cch.plot(datainput,ngroup)

# trial graph (limited)
#cch.plot_meanmean2(datainput,ngroup,0.577)
#cch.plot_range(datainput,ngroup,0.000,2.114)

#datmean = cch.mean(datainput)
#datmeanmean = cch.mean_mean(datainput,5)

#cch.plot_ewma(datainput,30,0.5)
