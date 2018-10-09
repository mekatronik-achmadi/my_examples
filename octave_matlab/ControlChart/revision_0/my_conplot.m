function [ dat_ucl, dat_cl, dat_lcl, dat_sampavg ] = my_conplot( datain, n_group )
% pusing bro, ada obat nyamuk?

% nilai control limit
[dat_ucl,dat_cl,dat_lcl,dat_sampavg] = my_conlimit(datain,n_group);

% generate axis
n_array = length(datain);
X_axis = zeros(n_array,1);
for i = 1:n_array
    X_axis(i) = i;
end

% buat nilai matrix control limit
UCL_array = ones(n_array,1) * dat_ucl;
CL_array =  ones(n_array,1) * dat_cl;
LCL_array =  ones(n_array,1) * dat_lcl;

% plot semua nilai
figure
plot(X_axis,UCL_array,'-r', ...
    X_axis,CL_array,'-r', ...
    X_axis,LCL_array,'-r', ...
    X_axis,datain,'--bo');
xlim([1 n_array])

end

