NEURON {
	SUFFIX capmp2
	USEION ca READ cao, ica, cai WRITE cai, ica
	RANGE tau, width, cabulk, ica, pump0
}
	
UNITS {
	(um)	=	(micron)
	(molar) =	(1/liter)
	(mM)	=	(millimolar)
	(uM)	= 	(micromolar)
	(mA)	=	(milliamp)
	(pmol)	=	(pico)
	FARADAY = 	(faraday)	(coulomb)
}

PARAMETER {
	width = .1 (um)
	tau = 1 (ms)
	k1 = 5e8	(/mM-s)
	k2 = .25e6	(/s)
	k3 = .5e3	(/s)
	k4 = 5e0	(/mM-s)
	cabulk = .1 (uM)
	pump0 = 3e-2 (pmol/cm2)
}

ASSIGNED {
	cao (mM) : 10
	cai (mM) : 1e-3
	ica (mA/cm2)
	ica_pmp (mA/cm2)
}

STATE {
	cam (uM)	<1e-6>
	pump (pmol/cm2)  <1e-4>
	capump (pmol/cm2) <1e-4>
}

INITIAL {
	SOLVE pmp STEADYSTATE sparse
}

BREAKPOINT {
	SOLVE pmp METHOD sparse
	ica = ica_pmp
}

KINETIC pmp {
	~ cabulk <-> cam (width/tau, width/tau)
	~ cam + pump <-> capump ((1e-5)*k1, (1e-2)*k2)
	~ capump <-> cao + pump ((1e-2)*k3, (1e-2)*k4)
	ica_pmp = (1e-7)*2*FARADAY*(f_flux - b_flux)

	~ cam << (-(ica - ica_pmp)/(2*FARADAY)*(1e7))

	CONSERVE pump + capump = (1e1)*pump0
	COMPARTMENT width {cam}	: volume has dimensions of um
	COMPARTMENT (1e1) {pump capump}	: area is dimensionless
	COMPARTMENT 1(um) {cabulk}
	COMPARTMENT (1e3)*1(um) {cao}

	cai = (.001)*cam
}

