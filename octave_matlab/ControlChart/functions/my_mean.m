function [ array_mean ] = my_mean( one_dim_array )
% pusing bro, ada obat nyamuk?

% dapatkan panjang array satu dimensi 
n_array = length(one_dim_array);

% hitung total
array_sum = 0;
for i = 1:n_array
    array_sum = array_sum + one_dim_array(i);
end
array_mean = array_sum/n_array;

end

