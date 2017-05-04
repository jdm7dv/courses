COMMENT
Since this is an electrode current, positive values of i depolarize the cell
and in the presence of the extracellular mechanism there will be a change
in vext since i is not a transmembrane current but a current injected
directly to the inside of the cell.
ENDCOMMENT

NEURON {
	POINT_PROCESS BadPulse
	RANGE del, dur, amp, i
	ELECTRODE_CURRENT i
}
UNITS {
	(nA) = (nanoamp)
}

PARAMETER {
	del (ms)
	dur (ms)	<0,1e9>
	amp (nA)
}
ASSIGNED { i (nA) }

INITIAL {
	i = 0
}

BREAKPOINT { LOCAL adel, adur
:	adel = at_time(del)
:	adur = at_time(del+dur)

	if (t < del + dur && t > del) {
		i = amp
	}else{
		i = 0
	}
:printf("adel=%g adur=%g ", adel, adur)
printf("t=%g t-del=%g v=%g i=%g\n", t, t-del, v, i)
}
