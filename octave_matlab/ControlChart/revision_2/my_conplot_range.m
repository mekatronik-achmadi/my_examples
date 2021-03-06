function [ dat_ucl, dat_lcl] = my_conplot_range( datain, n_group, kons_D3, kons_D4 )
% pusing bro, ada obat nyamuk?

% nilai control limit
[dat_ucl,dat_lcl] = my_conlimit_range(datain,n_group,kons_D3,kons_D4);

data_array =  my_data_range_group(datain, n_group);

% generate axis
n_array = length(data_array);
X_axis = zeros(n_array,1);
for i = 1:n_array
    X_axis(i) = i;
end

% buat nilai matrix control limit
UCL_array = ones(n_array,1) * dat_ucl;
LCL_array =  ones(n_array,1) * dat_lcl;

% plot semua nilai
figure
plot(X_axis,UCL_array,'-r', ...
    X_axis,data_array,'-g', ...
    X_axis,LCL_array,'-r');
xlim([1 n_array])

end

