close all
clear
clc

fs=1000;
n=0:1/fs:1;
x=(sin(2*pi*50*n))/(1);
figure
subplot(3,1,1)
plot(n,x)

N=2^nextpow2(length(x));
m=(-N/2):(N/2)-1;
w=2*pi*m*fs/N;
X=x*exp(-1i*n'*w);
subplot(3,1,2)
plot (w/(2*pi),abs(X))
xlim([-80 80])

filterku=w/(2*pi)>-40 & w/(2*pi)<40;
figure
subplot(2,1,1)
plot(w/(2*pi), filterku)
xlim([-80 80])
ylim ([0 1.25])
ynew=(1/N)*(X.*filterku)*exp(1i*w'*n);
ynew=real(ynew);
subplot(2,1,2)
plot(n,ynew)
