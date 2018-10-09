%Fenomenon Gibb
t=linspace(-2,2,2000); %untuk pengskalaan dimana skala dari -2 smp 2 dibagai 2000 skala
u=linspace(-2,4,2000);
sq=[zeros(1,500),2*ones(1,2000),zeros(1,500)]; %untuk sinyal merah 
k=2;
N=[-2,0.9,50,100,500,1000];
for n=1:6;
an=[];
for  m=1:N(n)
    			an=[an,2*k*sin(m*pi/2)/(m*pi)];
end;
fN=k/2;
for m=1:N(n)
    		fN=fN+an(m)*cos(m*pi*t/2);
end;
nq=int2str(N(n));
subplot(3,2,n),plot(u,sq,'r','LineWidth',2);hold on; %untuk ngeplot fungsi merah
plot(t,fN,'LineWidth',2 ); hold off; axis([-2 2 -0.5 2.5]);grid; %untuk ngeplot grafik biru
xlabel('Time'), ylabel('y_N(t)');title(['N= ',nq]);
end;
