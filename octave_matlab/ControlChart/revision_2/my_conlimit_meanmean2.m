function [ UCL, LCL ] = my_conlimit_meanmean2( datain, n_group, kons )
% calculate control limit based on data range each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount
% kons = lihat tabel 

% UCL, LCL = control limit

CL = my_meanofmean(datain, n_group);
dat_range = my_data_mean_range(datain, n_group);

UCL = CL + (kons*dat_range);
LCL = CL - (kons*dat_range);

end

