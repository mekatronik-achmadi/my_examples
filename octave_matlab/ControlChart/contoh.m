close all;
clear;
clc

addpath('functions')  

% ambil data
% total data 150 sample
load('engine_data.mat');
datainput=engine_AFR;

% grup data berdasarkan urutan
% n_group harus fit MxN
n_group = 30;
data_group = my_grouping(datainput,n_group);

%------------------ Mean --------------

% mean tiap grup
mean_each = zeros(n_group,1);
for i = 1:n_group
    mean_each(i) = my_mean(data_group(:,i));
end

% mean semua 
meanofmean = my_mean(mean_each);

% ---------------- Range --------------

range_each = zeros(n_group,1);
for i = 1:n_group
    range_each(i) = my_range(data_group(:,i));
end

% mean dari range
range_mean = my_mean(range_each);

% ---------------- Control Limit Mean ------------

kons = 0.577; % lihat tabel 

UCL_mean = meanofmean + (kons*range_mean);
LCL_mean = meanofmean - (kons*range_mean);

my_conplot(UCL_mean,LCL_mean,mean_each);

% ---------------- Control Limit Range ------------

konsD3 = 0.000; % lihat tabel
konsD4 = 2.114; % lihat tabel

UCL_range = konsD3*range_mean;
LCL_range = konsD4*range_mean;

my_conplot(UCL_range,LCL_range,range_each);




