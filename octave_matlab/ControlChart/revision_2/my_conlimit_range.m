function [ UCL, LCL ] = my_conlimit_range( datain, n_group, kons_D3, kons_D4 )
% calculate control limit based on data range each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount
% kons = lihat tabel 

% UCL, LCL = control limit

dat_range = my_data_mean_range(datain, n_group);

UCL = kons_D3*dat_range;
LCL = kons_D4*dat_range;

end

