function my_conplot( ucl, lcl, datain )
% plot control chart

% generate axis
n_array = length(datain);
X_axis = zeros(n_array,1);
for i = 1:n_array
    X_axis(i) = i;
end

% garis horizontal array
UCL_array = ones(n_array,1) * ucl;
LCL_array =  ones(n_array,1) * lcl;

% plot semua nilai
figure
plot(X_axis,UCL_array,'-r', ...
    X_axis,datain,'-g', ...
    X_axis,LCL_array,'-r');
xlim([1 n_array])

end

