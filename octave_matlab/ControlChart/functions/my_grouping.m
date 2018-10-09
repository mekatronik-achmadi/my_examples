function dataout = my_grouping( datain, n_group )
% grouping data based on data sequence with no other rules
% n_group must be fit to MxN dimension matrix of datain

% datain = raw data tanpa ada grouping
% n_group = group amount

% dataout = multi array grouping result

n_each = length(datain)/n_group;

dataout = zeros(n_each,n_group);
for i = 1:n_group
    for j = 1:n_each
        dataout(j,i) = datain(j*i);
    end
end

end

