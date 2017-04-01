#!/bin/sh

prefix=/usr/local/nrn
exec_prefix=/usr/local/nrn/x86_64
NRNBIN=${exec_prefix}/bin
ARCH=x86_64
NEURONHOME=/usr/local/nrn/share/nrn

cd $1

if [ -x ${ARCH}/special ] ; then
	program="./${ARCH}/special"
else
	program="${NRNBIN}/nrniv"
fi

hostname
pwd
shift
shift
echo "time $program $*"
time $program $*

