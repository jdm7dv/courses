#include <carl/cmusic.h>
#define FLTDELAY(b) fltdelay b d d d d d d d d d d d d d d d
set list = pluck40.l;
set srate = 16K;
set funclength = 1K;

ins 0 pluck0;
	FLTDELAY(b1) 0 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14;
	out b1;
end;

ins 0 pluck1;
	seg b3 p15 f2 d .025 0 .025;
	adn b2 p5 b3;
	FLTDELAY(b1) 0 b2 p6 p7 p8 p9 p10 p11 p12 p13 p14;
	out b1;
end;

GEN6(f1) ;
GEN4(f2) 0,0 0 .1,0 0 .9,1 0 1,1; {linear gliss}

{
#define IN	1	/* (bvpn) optional input block (for use as resonator)*/
#define PITCH	2	/* (bvpn) desired fundamental freq (use Hz postop !!)*/
#define DECAY	3	/* (bvpn) duration factor (0 to 1: 1 = full duration)*/
#define TABLE	4	/* (vpn) function to initialize table (eg. from gen6)*/
#define LEVEL	5	/* (vpn) amplitude of pluck  (0 to 1:  1  =  loudest)*/
#define FINAL	6	/* (vpn) number of db down at p4 (0 to 90: 40 = norm)*/
#define ONSET	7	/* (vpn) attack time for pluck(0 to .1 sec: 0 = fast)*/
#define PLACE	8	/* (vpn) pluck point on string  (0 to .5: 0 = normal)*/
#define FILTR	9	/* (vpn) lowpass prefilter cutoff freq(0 to .5 Srate)*/
#define NOISE	10	/* (vpn) time of initial noise burst (-1 to +0.1 sec)*/
#define STIFF	11	/* (vpn) stiffness (0 to 10:  10 = stiffest/sharpest)*/
}
note 0		pluck0	1.	C(2)	1	1	1	40	.001		0	.5	0	0;
note .5		pluck0	1.	G(1)	1	1	.5	40	.001		0	.5	0	0;
note 1		pluck0	1.	E(1)	1	1	.5	40	.001		0	.5	0	0;
note 1.5	pluck0	1.	C(1)	1	1	1	40	.001		0	.5	0	0;
note 2		pluck0	1.	G(0)	1	1	.5	40	.002		0	.5	0	0;
note 2.5	pluck0	1.	E(0)	1	1	.5	40	.002		0	.5	0	0;
note 3		pluck0	1.	C(0)	1	1	1	40	.002		0	.5	0	0;
note 3.5	pluck0	1.	Bf(-1)	1	1	.5	40	.003		0	.5	0	0;
note 4		pluck0	1.	G(-1)	1	1	.5	40	.005		0	.5	0	0;
note 4.5	pluck0	1.	E(-1)	1	1	1	40	.005		0	.5	0	0;
note 5		pluck0	1.	C(-1)	1	1	.5	40	.005		0	.5	0	0;
note 5.5	pluck0	1.	Bf(-2)	1	1	.5	40	.005		0	.5	0	0;
note 6		pluck0	1.5	A(-2)	1	1	.5	30	.005		0	.5	0	0;
note 6.1	pluck0	1.4	Cs(-1)	1	1	.25	30	.005		0	.5	0	0;
note 6.2	pluck0	1.3	E(-1)	1	1	.25	30	.005		0	.5	0	0;
note 6.3	pluck0	1.2	A(-1)	1	1	.25	30	.005		0	.5	0	0;
note 7.5	pluck0	1.5	109.8Hz	1	1	.5	30	.01		0	.5	0	0;
note 7.5	pluck0	1.5	110.2Hz	1	1	.5	30	.01		0	.5	0	0;
note 9		pluck0	1.	D(-1)	1	1	1	40	.003		0	.5	0	0;
note 9.5	pluck0	1.	D(-1)	1	1	1	40	.003		0	.1	0	0;
note 10		pluck0	1.	D(-1)	1	1	.5	40	.003		0	.5	-.1	0;
note 10.5	pluck0	1.	D(-1)	1	1	1	40	.003		.5	.5	0	0;
note 11		pluck0	1.	D(-1)	1	1	.5	40	.003		.33	.5	0	0;
note 11.5	pluck0	1.	D(-1)	1	1	.5	40	.003		.2	.5	0	0;
note 12		pluck0	1.	D(-1)	1	1	1	40	.003		.1	.5	0	0;
note 12.5	pluck0	1.	D(-1)	1	1	.5	40	.003		0	.5	0	4;
note 13		pluck0	1.	D(-1)	1	1	.5	40	.003		0	.5	0	7;
note 13.5	pluck1	1.5	D(-2)	-1	1	1	40	.003		0	.5	0	0	D(-2) ;
ter;
