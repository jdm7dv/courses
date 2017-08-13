#include <carl/cmusic.h>
set list = tmx.list;
set stereo;

ins 0 one;
{carrier} 	osc  b1 p5 p6 f1 d;
		SPACE(b1,1) 10 10 0 1 1 ;
end;

SINE(f1);

note 0 one 1 .73 440Hz;
ter ;
