#include <carl/cmusic.h>
set list = sp.list;
set stereo;
set funclength = 8K;
set revscale = .1;
set t60 = 3;
set cutoff = -60dB;


ins 0 one;
{env}		seg  b4 p5 f4 d .1sec 0 .1sec;
{x}		osc  b2 p7 p8 f2 d;
{y}		osc  b3 p7 p9 f3 d;
{carrier} 	osc  b1 p5 p6 f1 d;
		SPACE(b1,1) b2 b3 0 1 0dB;
end;

SAWTOOTH(f1);

GEN3(f2) -20 20 -20 20;

GEN3(f3) 10 10;

GEN3(f4) 0 1 1 0;

note 0 one 8 0dB 240Hz 1 p4sec p4sec;
{
note 3 one 8 0dB 257Hz 10 4Hz 4Hz 11Hz 16;
note 6 one 8 0dB 57Hz 40 1Hz 1Hz 6Hz 0;
}

sec;
ter 4;
