load('engine_data.mat');
datainput=engine_AFR;
[UCL,CL,LCL]=my_conplot_meanmean(datainput,30);
