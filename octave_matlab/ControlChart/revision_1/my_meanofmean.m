function [ meanofmean ] = my_meanofmean( datain, n_group )
% calculate mean of mean each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% meanofmean = single value of mean of group mean

mean_each = my_mean_group(datain,n_group);
meanofmean = my_mean(mean_each);

end

