#include <carl/cmusic.h>
set list = xxx.list;
set stereo;
set funclength = 8K;
set revscale = 0;
set t60 = 3;
set cutoff = -60dB;


ins 0 one;
{env}		seg  b4 p5 f4 d .1sec 0 .1sec;
{pulser}	osc  b5 b4 p10 f5 d;
{x}		osc  b2 p7 p8 f2 d;
{y}		osc  b3 p7 p9 f3 d;
{front}		adn  b3 b3 p11;
{carrier} 	osc  b1 b5 p6 f1 d;
		SPACE(b1,1) b2 b3 0 1 0dB;
end;

GEN5(f1) 1,1,0 2,1,0 4,1,0; NORM(f1);
SINE(f2);
COS(f3);
GEN1(f4) 0,0 1/3,1 2/3,1 1,0;
GEN4(f5) 0,0 -9 .1,1 -2 1,0;
GEN3(f6) 3/4 -1/4;

note 0 one 4 0dB 1000Hz 10 2sec 2sec 11Hz 12;
{
note 3 one 8 0dB 257Hz 10 4Hz 4Hz 11Hz 16;
note 6 one 8 0dB 57Hz 40 1Hz 1Hz 6Hz 0;
}

sec;
ter 2;
