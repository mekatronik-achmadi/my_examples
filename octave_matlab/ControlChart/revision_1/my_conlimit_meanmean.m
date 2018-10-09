function [ UCL, CL, LCL ] = my_conlimit_meanmean( datain, n_group )
% calculate control limit based on mean of mean

CL = my_meanofmean(datain, n_group);
dat_sampavg = my_sample_avg_meanmean(datain, n_group);

UCL = CL + (3*dat_sampavg);
LCL = CL - (3*dat_sampavg);
end

