function dataout = my_grouping( datain, n_group )
% n_group = group amunt
% based on data sequence with no other rules

n_each = length(datain)/n_group;

dataout = zeros(n_each,n_group);
for i = 1:n_group
    for j = 1:n_each
        dataout(j,i) = datain(j*i);
    end
end

end

