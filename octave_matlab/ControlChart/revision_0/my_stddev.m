function [ array_stddev, array_mean ] = my_stddev( one_dim_array )
% pusing bro, ada obat nyamuk?

% dapatkan panjang array
n_array = length(one_dim_array);

% dapatkan nilai mean
array_mean = my_mean(one_dim_array);

% dapatkan stddev kuadrat
stddev_sum = 0;
for i = 1:n_array
    stddev_sum = stddev_sum+((one_dim_array(i)-array_mean)^2);
end
array_stddev = sqrt(stddev_sum/n_array);

end

