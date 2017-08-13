#include <carl/cmusic.h>
set list = ioc.list;
set quad; 
set revscale = .068; 
set t60 = 2.5;
set cutoff = -60dB; 

set room = 1.5,1.5 -1.5,1.5 -1.5,-1.5 1.5,-1.5;
set speakers = 1.5,1.5 -1.5,1.5 -1.5,-1.5 1.5,-1.5;
set space = 50,50 -50,50 -50,-50 50,-50;
set funclength = 8K;

ins 0 one;
{x sweep}	osc  b2 1 p5 f3 d;
{env}		osc  b1 p6 5Hz f2 d;
{carrier} 	osc  b1 b1 p7 f1 d;
		SPACE(b1,1) b2 b2 0 1 0dB;
end;

SAWTOOTH(f1);
PLUCKENV(f2) ;
GEN3(f3) -10 1 -10 ;

note    0 one 4 p4sec 0dB 500Hz -5 2 ;
sec;
ter 3;
