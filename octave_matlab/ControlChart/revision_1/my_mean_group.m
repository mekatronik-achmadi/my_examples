function [ mean_each ] = my_mean_group( datain, n_group )
% calculate mean each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% mean_each = single array of group mean

data_group = my_grouping(datain,n_group);

mean_each = zeros(n_group,1);
for i = 1:n_group
    mean_each(i) = my_mean(data_group(:,i));
end

end

