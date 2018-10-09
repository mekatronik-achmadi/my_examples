function [ array_stddev ] = my_stddev_meanmean( one_dim_array, n_group )

n_array = length(one_dim_array);
array_mean = my_meanofmean(one_dim_array,n_group);

stddev_sum = 0;
for i = 1:n_array
    stddev_sum = stddev_sum+((one_dim_array(i)-array_mean)^2);
end
array_stddev = sqrt(stddev_sum/n_array);

end

