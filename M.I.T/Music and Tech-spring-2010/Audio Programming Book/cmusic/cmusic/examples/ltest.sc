#include <carl/cmusic.h>
set list = ltest.list;
set stereo;
set funclength = 8K;
set revscale = .1;
set t60 = 3;
set cutoff = -60dB;


ins 0 one;
{env}		seg  b4 p5 f4 d .1sec 0 .1sec;
{x}		iosc  b2 p7 p8 f2 d;
{y}		iosc  b3 p7 p9 f3 d;
{front}		adn  b3 b3 p11;
{carrier} 	osc  b1 b4 p6 f1 d;
		SPACE(b1,1) b2 b3 0 1 0dB;
end;

SAWTOOTH(f1);

GEN3(f2) 0 1 -1 0;

GEN3(f3) 1 0 -1 0 1;

GEN1(f4) 0,0 1/3,1 2/3,1 1,0;

PULSE(f5);

note 0 one 4 0dB 110Hz 10 p4/2sec p4/2sec 11Hz 15;
{
note 3 one 8 0dB 257Hz 10 4Hz 4Hz 11Hz 16;
note 6 one 8 0dB 57Hz 40 1Hz 1Hz 6Hz 0;
}

sec;
ter 4;
