: Three state kinetic scheme for HH potassium channel

NEURON {
	SUFFIX khh
	USEION k READ ek WRITE ik
	RANGE g, gbar
	GLOBAL a1, b1, a2, b2, K1, K2, tau1, tau2
}

PARAMETER {
	gbar = 22 (millimho/cm2)

	: fit of steady state conductance vs vc
	d1 = 21 (millivolt)
	k1 = .2 (/millivolt)
	d2 = 43 (millivolt)
	k2 = .036 (/millivolt)

	ta1 = 4.4 (ms)
	tk1 = -.025 (/millivolt)
	ta2 = 2.6 (ms)
	tk2 = -.007 (/millivolt)

	:vrest = -65 (millivolt)
	vrest = 0 (millivolt)	 : for original hh data
}

ASSIGNED {
	v (millivolt)
	g (millimho/cm2)
	ik (milliamp/cm2)
	ek (millivolt)

	K1
	K2
	tau1(ms) tau2(ms)
	a1(/ms) b1(/ms) a2(/ms) b2(/ms)
}
	
STATE {c1 c2  o}

INITIAL {
	SOLVE kin STEADYSTATE sparse
}

BREAKPOINT {
	SOLVE kin METHOD sparse
	g = gbar*o
	ik = g*(v - ek)*(1e-3)
}

KINETIC kin {
	rates(v) :
	~ c1 <-> c2	(a1, b1)
	~ c2 <-> o	(a2, b2)
	CONSERVE c1 + c2 + o = 1
}

PROCEDURE rates(v(millivolt)) {
	LOCAL vr
	vr = v - vrest : v = vrest means rates at 0

	K2 = exp(-(k2*(d2 - vr)))
	K1 = exp((k2*(d2 - vr)) - (k1*(d1 - vr)))
	tau1 = ta1*exp(tk1*vr)
	tau2 = ta2*exp(tk2*vr)

	a1 = K1/(tau1*(K1+1))
	b1 =  1/(tau1*(K1+1))
	a2 = K2/(tau2*(K2+1))
	b2 = 1/(tau2*(K2+1))
}
