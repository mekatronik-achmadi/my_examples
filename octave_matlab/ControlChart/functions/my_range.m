function [ vrange ] = my_range( one_dim_array )

vmax = max(one_dim_array);
vmin = min(one_dim_array);

vrange = abs(vmax-vmin);

end

