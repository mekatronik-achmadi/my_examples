function [ dat_mean, dat_stddev, dat_meanmean, dat_sampavg, dat_stddevgrp ] = my_avgsamp( datain, n_group )
% pusing bro, ada obat nyamuk?

% nilai standar
dat_mean = my_mean(datain);
dat_stddev = my_stddev(datain);

% grouping nilai
data_group = my_grouping(datain, n_group);

% nilai mean and stddev tiap grup
mean_each = zeros(n_group,1);
stddev_each = zeros(n_group,1);
for i = 1:n_group
    mean_each(i) = my_mean(data_group(:,i));
    stddev_each(i) = my_sttdev(data_group(:,i));
end
dat_meanmean = my_mean(mean_each);

% nilai sample avg
dat_sampavg = dat_stddev/sqrt(n_group);

end

