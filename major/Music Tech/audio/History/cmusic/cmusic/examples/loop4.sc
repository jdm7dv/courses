#include <carl/cmusic.h>
set list = loop4.list;
set quad;
set funclength = 8K;
set revscale = .1;
set t60 = 3;
set cutoff = -60dB;

#define FILENAME s1
#define DEFSTRING(string)var p2 string 

DEFSTRING(FILENAME) "path.out" ;

ins 0 one;
{env}		seg  b4 p5 f4 d .1sec 0 .1sec;
{pulser}	osc  b5 b4 p10 f5 d;
{x}		osc  b2 p7 p8 f2 d;
{y}		osc  b3 p7 p9 f3 d;
{front}		adn  b3 b3 p11;
{carrier} 	osc  b1 b5 p6 f1 d;
		showpath b2 b3 FILENAME d d d;
		SPACE(b1,1) b2 b3 0 1 0dB;
end;

SAWTOOTH(f1);

SINE(f2);

COS(f3);

GEN1(f4) 0,0 1/3,1 2/3,1 1,0;

PULSE(f5);

GEN3(f6) 3/4 -1/4;

note 0 one 4 0dB 440Hz 10 2sec 2sec 11Hz 0;
{
note 3 one 8 0dB 257Hz 10 4Hz 4Hz 11Hz 16;
note 6 one 8 0dB 57Hz 40 1Hz 1Hz 6Hz 0;
}

sec;
ter 4;
