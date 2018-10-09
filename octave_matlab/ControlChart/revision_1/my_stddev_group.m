function [ stddev_each ] = my_stddev_group( datain, n_group )
% calculate stddev each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% % stddev_each = single array of group stddev

data_group = my_grouping(datain,n_group);

stddev_each = zeros(n_group,1);
for i = 1:n_group
    stddev_each(i) = my_stddev(data_group(:,i));
end

end

