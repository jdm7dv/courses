#include <carl/cmusic.h>

set list ;
set stereo ;
set srate = 44.1K ;

set funclength = 8K;

ins 0 toot;
	seg  b2 p5 f2 d 0 ;
	osc  b1 b2 p6 f1 d ;
	out b1, b1 ;
end;

SINE(f1) ;
GEN4(f2) 0,0 -1 .2,1 0 .8,1 -1 1,0 ;

note 0 toot 2 -3dB 440Hz ;
note 3 toot 2 -6dB 880Hz ;


ter 60 ; 
