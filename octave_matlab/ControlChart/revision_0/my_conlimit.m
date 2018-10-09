function [ dat_ucl, dat_cl, dat_lcl, dat_sampavg ] = my_conlimit( datain, n_group )
% pusing bro, ada obat nyamuk?

[dat_stddev, dat_mean] = my_stddev(datain);

dat_sampavg = dat_stddev/sqrt(n_group);

dat_cl = dat_mean;
dat_ucl = dat_cl + (3*dat_sampavg);
dat_lcl = dat_cl - (3*dat_sampavg);

end

