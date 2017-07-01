% at rest V=-64.9964 m=0.0530 h=0.5960 n=0.3177 
% time msec, conductance mS/mm^2, voltage mV, capacitance uF/mm^2
gkmax=0.36; vk=-77; 
gnamax=1.2; vna=50; 
gl=0.003; vl=-54.387; 
cm=0.010; 

niter=10000; dt=0.1; t=(1:niter)*dt;

iapp=0.05*ones(niter,1);

v=-64.9964; m=0.0530; h=0.5960; n=0.3177;

gnahist=zeros(niter,1); gkhist=zeros(niter,1);
vhist=zeros(niter,1);
mhist=zeros(niter,1); hhist=zeros(niter,1); nhist=zeros(niter,1);

for iter=1:niter
  gna=gnamax*m^3*h; gk=gkmax*n^4; gtot=gna+gk+gl;
  vinf = (gna*vna+gk*vk+gl*vl + iapp(iter))/gtot;
  tauv = cm/gtot;
  v=vinf+(v-vinf)*exp(-dt/tauv);
  alpham = 0.1*(v+40)/(1-exp(-(v+40)/10));
  betam = 4*exp(-0.0556*(v+65));
  alphan = 0.01*(v+55)/(1-exp(-(v+55)/10));
  betan = 0.125*exp(-(v+65)/80);
  alphah = 0.07*exp(-0.05*(v+65));
  betah = 1/(1+exp(-0.1*(v+35)));
  taum = 1/(alpham+betam); tauh = 1/(alphah+betah); taun = 1/(alphan+betan);
  minf = alpham*taum; hinf = alphah*tauh; ninf = alphan*taun;
  m=minf+(m-minf)*exp(-dt/taum);
  h=hinf+(h-hinf)*exp(-dt/tauh);
  n=ninf+(n-ninf)*exp(-dt/taun);
  vhist(iter)=v; mhist(iter)=m; hhist(iter)=h; nhist(iter)=n;
end

subplot(2,1,1)
plot(t,vhist);
title('voltage vs. time')

subplot(2,1,2)
plot(t, [mhist,hhist,nhist]);
legend('m','h','n')