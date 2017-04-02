#include <carl/cmusic.h>
set stereo;
set func = 8K;

ins 0 one;
		seg  b1 p6 f2 d 0;
{carrier} 	osc  b1 b1 p5 f1 d;
{output} 	out  b1 0;
end;

ins 0 two;
		seg  b1 p6 f2 d 0;
{carrier} 	osc  b1 b1 p5 f1 d;
{output} 	out  0 b1;
end;

SINE(f1);
GEN4(f2) 0,0 -1 .1,1 0 .8,1 -1 1,0;

#define T p2+p4

note 0 one .2 440Hz 0dB;
note T two .1 1000Hz 0dB;
note T two .1 1000Hz 0dB;
note T one .2 440Hz 0dB;
note T two .1 1000Hz 0dB;
note T two .1 1000Hz 0dB;
note T one .2 440Hz 0dB;
note T two .1 1000Hz 0dB;
note T two .1 1000Hz 0dB;
note T one .2 440Hz 0dB;
note T two .1 1000Hz 0dB;
note T two .1 1000Hz 0dB;
note T  one 5 440Hz 0dB;
note T two 5 1000Hz 0dB;

ter ;
