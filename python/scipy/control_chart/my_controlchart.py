#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 12 21:02:30 2017

@author: achmadi

pusing bro, ada obat nyamuk?
"""

# import modules
import math as mt
import numpy as np
import matplotlib.pyplot as plt

class MyControlChart:
    def __init__(self):
        pass
    
    def grouping(self,datain,n_group):
        n_each = int(datain.size/n_group)
        dataout = np.zeros((n_each,n_group))
        for i in range(0,n_group):
            for j in range(0,int(n_each)):
                dataout[j,i] = datain[(n_each*i)+j]
        return dataout 
    
    def mean(self,one_dim_array):
        n_array = one_dim_array.size
        array_sum = 0
        for i in range(0,n_array):
            array_sum = array_sum + one_dim_array[i]
        array_mean = array_sum / n_array;
        return array_mean    
  
    def stddev(self,one_dim_array):
        n_array = one_dim_array.size
        array_mean = self.mean(one_dim_array)
        stddev_sum = 0
        for i in range(0,n_array):
            stddev_sum = stddev_sum + mt.pow((one_dim_array[i]-array_mean),2)
        array_stddev = mt.sqrt(stddev_sum/n_array)
        return array_stddev  
    
    def sample_avg(self,datain,n_group):
        array_stddev = self.stddev(datain)
        data_smp_avg = array_stddev/mt.sqrt(n_group)
        return data_smp_avg
    
    def data_cl(self,datain):
        return self.mean(datain)    
    
    def data_ucl(self,datain,n_group):
        dat_cl = self.data_cl(datain)
        dat_smpavg = self.sample_avg(datain,n_group)
        dat_ucl = dat_cl + (3*dat_smpavg)
        return dat_ucl
    
    def data_lcl(self,datain,n_group):
        dat_cl = self.data_cl(datain)
        dat_smpavg = self.sample_avg(datain,n_group)
        dat_lcl = dat_cl - (3*dat_smpavg)
        return dat_lcl
    
    def plot(self,datain,n_group):
        x_axis = np.arange(0, datain.size, 1)
        line_cl = np.ones((datain.size,1))*self.data_cl(datain)
        line_ucl = np.ones((datain.size,1))*self.data_ucl(datain,n_group)
        line_lcl = np.ones((datain.size,1))*self.data_lcl(datain,n_group)
        plt.figure()
        plt.plot(x_axis,line_ucl,'r')
        plt.plot(x_axis,line_cl,'r')
        plt.plot(x_axis,line_lcl,'r')
        plt.plot(x_axis,datain,'--bo')
        plt.xlim((0,datain.size))
        plt.xlabel('sample')
        plt.ylabel('value')
        plt.grid()
        plt.show()
        
# -------------------- Use data grouping -------------------------
        
    def stddev_group(self,datain,n_group):
        data_group = self.grouping(datain,n_group)
        stddev_each = np.zeros((n_group,1))
        for i in range(0,n_group):
            stddev_each[i] = self.stddev(data_group[:,i])
        return stddev_each

    def mean_group(self,datain,n_group):
        data_group = self.grouping(datain,n_group)
        mean_each = np.zeros((n_group,1))
        for i in range(0,n_group):
            mean_each[i] = self.mean(data_group[:,i])
        return mean_each       
    
    def mean_mean(self,datain,n_group):
        data_group = self.grouping(datain,n_group)
        mean_each = np.zeros((n_group,1))
        for i in range(0,n_group):
            mean_each[i] = self.mean(data_group[:,i])
        data_meanofmean = self.mean(mean_each)
        return data_meanofmean   
   
    def stddev_meanmean(self,one_dim_array,n_group):
        n_array = one_dim_array.size
        array_mean = self.mean_mean(one_dim_array,n_group)
        stddev_sum = 0
        for i in range(0,n_array):
            stddev_sum = stddev_sum + mt.pow((one_dim_array[i]-array_mean),2)
        array_stddev = mt.sqrt(stddev_sum/n_array)
        return array_stddev
    
    def sample_avg_meanmean(self,datain,n_group):
        array_stddev = self.stddev_meanmean(datain,n_group)
        data_smp_avg = array_stddev/mt.sqrt(n_group)
        return data_smp_avg
    
    def data_cl_meanmean(self,datain,n_group):
        return self.mean_mean(datain,n_group)
    
    def data_ucl_meanmean(self,datain,n_group):
        dat_cl = self.data_cl_meanmean(datain,n_group)
        dat_smpavg = self.sample_avg_meanmean(datain,n_group)
        dat_ucl = dat_cl + (3*dat_smpavg)
        return dat_ucl
    
    def data_lcl_meanmean(self,datain,n_group):
        dat_cl = self.data_cl_meanmean(datain,n_group)
        dat_smpavg = self.sample_avg_meanmean(datain,n_group)
        dat_lcl = dat_cl - (3*dat_smpavg)
        return dat_lcl
    
    def plot_meanmean(self,datain,n_group):
        x_axis = np.arange(0, datain.size, 1)
        line_cl = np.ones((datain.size,1))*self.data_cl_meanmean(datain,n_group)
        line_ucl = np.ones((datain.size,1))*self.data_ucl_meanmean(datain,n_group)
        line_lcl = np.ones((datain.size,1))*self.data_lcl_meanmean(datain,n_group)
        plt.figure()
        plt.plot(x_axis,line_ucl,'r')
        plt.plot(x_axis,line_cl,'r')
        plt.plot(x_axis,line_lcl,'r')
        plt.plot(x_axis,datain,'--bo')
        plt.xlim((0,datain.size))
        plt.xlabel('sample')
        plt.ylabel('value')
        plt.grid()
        plt.show()
        
# -------------------- revision -------------------------

    def data_range(self,one_dim_array):
        vmax = np.amax(one_dim_array)
        vmin = np.amin(one_dim_array)
        vrange = np.absolute(vmax-vmin)
        return vrange
    
    def data_range_group(self,datain,n_group):
        data_group = self.grouping(datain,n_group)
        range_each = np.zeros((n_group,1))
        for i in range(0,n_group):
            range_each[i] = self.data_range(data_group[:,i])
        return range_each
    
    def data_mean_range(self,datain,n_group):
        range_group = self.data_range_group(datain,n_group)
        mean_range = self.mean(range_group)
        return mean_range
    
    def data_ucl_meanmean2(self,datain,n_group,kons):
        dat_cl = self.data_cl_meanmean(datain,n_group)
        dat_range = self.data_mean_range(datain,n_group)
        dat_ucl = dat_cl + (kons*dat_range)
        return dat_ucl
    
    def data_lcl_meanmean2(self,datain,n_group,kons):
        dat_cl = self.data_cl_meanmean(datain,n_group)
        dat_range = self.data_mean_range(datain,n_group)
        dat_lcl = dat_cl - (kons*dat_range)
        return dat_lcl
    
    def plot_meanmean2(self,datain,n_group,kons):
        line_mean = self.mean_group(datain,n_group)
        x_axis = np.arange(0, line_mean.size, 1)
        line_ucl = np.ones((line_mean.size,1))*self.data_ucl_meanmean2(datain,n_group,kons)
        line_lcl = np.ones((line_mean.size,1))*self.data_lcl_meanmean2(datain,n_group,kons)      
        plt.figure()
        plt.plot(x_axis,line_ucl,'r')
        plt.plot(x_axis,line_lcl,'r')
        plt.plot(x_axis,line_mean,'b')
        plt.xlim((0,line_mean.size))
        plt.xlabel('sample')
        plt.ylabel('value')
        plt.grid()
        plt.show()
        
    def data_ucl_range(self,datain,n_group,kons):
        dat_range_mean = self.data_mean_range(datain,n_group)
        dat_ucl = kons*dat_range_mean
        return dat_ucl
    
    def data_lcl_range(self,datain,n_group,kons):
        dat_range_mean = self.data_mean_range(datain,n_group)
        dat_lcl = kons*dat_range_mean
        return dat_lcl
    
    def plot_range(self,datain,n_group,kons3,kons4):
        line_range = self.data_range_group(datain,n_group) 
        x_axis = np.arange(0, line_range.size, 1)
        line_ucl = np.ones((line_range.size,1))*self.data_ucl_range(datain,n_group,kons3)
        line_lcl = np.ones((line_range.size,1))*self.data_lcl_range(datain,n_group,kons4)
        plt.figure()
        plt.plot(x_axis,line_ucl,'r')
        plt.plot(x_axis,line_lcl,'r')
        plt.plot(x_axis,line_range,'b')
        plt.xlim((0,line_range.size))
        plt.xlabel('sample')
        plt.ylabel('value')
        plt.grid()
        plt.show()
        
# -------------------- ewma -------------------------

    def ewma_data(self,datain,n_group,lamb):
        mean_each = self.mean_group(datain, n_group)
        
        data_z = np.zeros((datain.size,1)) 
        n_each = int(data_z.size/n_group)
        
        for i in range(0,n_group):
            for j in range(0,n_each):
                if i == 0 and j == 0:
                    data_z[0] = self.mean_mean(datain,n_group)
                else:
                    data_z[(i*n_each)+j] = lamb*mean_each[i] + (1+lamb)*data_z[((i*n_each)+j)-1]
        return data_z
                
    def ewma_ucl(self,datain,n_group,lamb):
        meanofmean = self.mean_mean(datain,n_group)
        datsamavg = self.sample_avg_meanmean(datain,n_group)
        
        ucl_val = meanofmean + (3*datsamavg*mt.sqrt(lamb/((2-lamb)*n_group)))
        return ucl_val
    
    def ewma_lcl(self,datain,n_group,lamb):
        meanofmean = self.mean_mean(datain,n_group)
        datsamavg = self.sample_avg_meanmean(datain,n_group)
        
        lcl_val = meanofmean - (3*datsamavg*mt.sqrt(lamb/((2-lamb)*n_group)))
        return lcl_val
            
    def plot_ewma(self,datain,n_group,lamb):
        line_ewma = self.ewma_data(datain,n_group,lamb)
        x_axis = np.arange(0, line_ewma.size, 1)
        line_ucl = np.ones((line_ewma.size,1))*self.ewma_ucl(datain,n_group,lamb)
        line_lcl = np.ones((line_ewma.size,1))*self.ewma_lcl(datain,n_group,lamb)
        plt.figure()
        plt.plot(x_axis,line_ucl,'r')
        plt.plot(x_axis,line_lcl,'r')
        plt.plot(x_axis,line_ewma,'b')
        plt.xlim((0,line_ewma.size))
        plt.xlabel('sample')
        plt.ylabel('value')
        plt.grid()
        plt.show()
        
# -------------------- shewart -------------------------

    def shewart_ucl(self,datain,kons):
        meandata = self.mean(datain)
        stddevdata = self.stddev(datain)
        
        ucl_val = meandata + kons*stddevdata
        return ucl_val
    
    def shewart_lcl(self,datain,kons):
        meandata = self.mean(datain)
        stddevdata = self.stddev(datain)
        
        lcl_val = meandata - kons*stddevdata             
                     
        # if there's no negative values
        if lcl_val < 0:
            lcl_val = 0
        
        return lcl_val
    
    def plot_shewart(self,datain,kons):
        line_data = datain
        x_axis = np.arange(0, line_data.size, 1)
        line_ucl = np.ones((line_data.size,1))*self.shewart_ucl(datain,kons)
        line_lcl = np.ones((line_data.size,1))*self.shewart_lcl(datain,kons)
        plt.figure()
        plt.plot(x_axis,line_ucl,'r')
        plt.plot(x_axis,line_lcl,'r')
        plt.plot(x_axis,line_data,'b')
        plt.xlim((0,line_data.size))
        plt.xlabel('sample')
        plt.ylabel('value')
        plt.grid()
        plt.show()
