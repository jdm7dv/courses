#include <carl/cmusic.h>
set list = nres.list;

ins 0 test;
{carrier} 	osc  b1 p5 p6 f1 d;
		NRES(b1,b1,1.,0,4KHz);
		out b1;
end;

PULSE(f1);

note 0 test 1 0dB 1024Hz ;
ter;
