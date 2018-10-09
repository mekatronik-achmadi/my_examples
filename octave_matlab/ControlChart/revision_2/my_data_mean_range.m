function [ mean_range ] = my_data_mean_range( datain, n_group )
% calculate mean of data range each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% mean_range = single value mean of group range

range_group = my_data_range_group(datain,n_group);
mean_range = my_mean(range_group);

end

