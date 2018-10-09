function [ range_each ] = my_data_range_group( datain, n_group )
% calculate data range each group
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% range_each = single array of group range

data_group = my_grouping(datain,n_group);
range_each = zeros(n_group,1);

for i = 1:n_group
    range_each(i) = my_data_range(data_group(:,i));
end

end

