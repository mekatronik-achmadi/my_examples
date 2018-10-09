function [ data_smp_avg ] = my_sample_avg_meanmean( datain, n_group )
% calculate sample average
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% data_smp_avg = single value of mean of group mean

array_stddev = my_stddev_meanmean(datain, n_group);
data_smp_avg = array_stddev/sqrt(n_group);

end

