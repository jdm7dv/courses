#include <carl/cmusic.h>
set list = io.list;
set stereo;
set funclength = 8K;
set revscale = .2;
set t60 = 3;
set cutoff = -60dB;


ins 0 one;
{env}		osc  b1 p6 p5 f2 d;
{carrier} 	osc  b1 b1 p7 f1 d;
		SPACE(b1,1) p8 p9 0 1 0dB;
end;

TRIANGLE(f1);
PLUCKENV(f2);

note    0 one .2 p4sec 0dB 1000Hz -5 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz -5 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz -5 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz -5 2 ;
sec;
sec 1;
note    0 one .2 p4sec 0dB 1000Hz 0 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz 0 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz 0 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz 0 2 ;
sec;
sec 1;
note    0 one .2 p4sec 0dB 1000Hz 5 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz 5 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz 5 2 ;
note p2+1 one .2 p4sec 0dB 1000Hz 5 2 ;
sec;
ter 3;
