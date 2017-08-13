: rectifying gap junction. Can only be used in conjunction with
: extracellular mechanism and the LinearMechanism class

NEURON {
	POINT_PROCESS RectifyingGapJunction
	RANGE g, i
	NONSPECIFIC_CURRENT i
}

PARAMETER {
	g = 0 (microsiemens)
}

ASSIGNED {
	v (millivolt)
	i (nanoamp)
}

BREAKPOINT {
	if (v > 0) {
		i = g*v
	}else{
		i = 0
	}
}

