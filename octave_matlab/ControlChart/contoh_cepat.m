close all;
clear;
clc

addpath('revision_2')  

load('engine_data.mat');
datainput=engine_AFR;
my_conplot_meanmean2(datainput,30,0.577);
my_conplot_range(datainput,30,0.000,2.114);
