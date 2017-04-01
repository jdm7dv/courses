NEURON {
	POINT_PROCESS ClampExData
}

ASSIGNED {
	pointer
}

VERBATIM
extern double chkarg();

typedef struct CEXData {
#if 1
	char header[1024];
#else
	float parm_[80];
	char comment_[77];
	char labels[5][16];
	char reserve1[35];
	char cond_pulse[64];
	long parm_extension[16];
	float adc_ext_offset[16];
	float adc_ext_gain[16];
	float adc_disp_amp[16];
	float adc_disp_offset[16];
	char  adc_units[16][8];
#endif
	short* data;
}CEXData;
#define CEXD CEXData* cexd = (CEXData*)((unsigned long)pointer);
	
static void reverse(b, n ) char* b; int n; {
	int i, j, v_;
	for (i=0, j=n-1; i<j; ++i, --j) {
		v_ = b[i];
		b[i] = b[j];
		b[j] = v_;
	}
}

static void header_endian(h) char* h; {
	char* b;
	int i;
	b = h;
	for (i=0; i < 80; ++i) {/* parameters */
		reverse(b, 4);
		b += 4;
	}
	b += (77 + 80 + 35 + 64);
	for (i=0; i < 16; ++i) {/* parameter extension */
		reverse(b, 4);
		b += 4;
	}
	for (i=0; i < 64; ++i) {
		reverse(b, 4);
		b += 4;
	}
}

static double get_parm(i, h) int i; char* h; {
	char* b;
	float* f;
	long* n;
	b = h;
	if (i <= 80) {
		f = (float*)b;
		return (double)f[i-1];
	}
	b += 320 + 77 + 80 + 35 + 64;
	if (i <= 96) {
		f = (float*)b;
		return (double)f[i- 81];
	}
	b += 64;
	if (i <= 160) {
		f = (float*)b;
		return (double)f[i - 97];
	}
	return 0.;
}
		
ENDVERBATIM

CONSTRUCTOR {
	VERBATIM	
	FILE* fin;
	int endian = 0;
	int samples, episodes;
	CEXData* cexd;
	char* fname;
	fname = gargstr(2);
	printf("fname = %s\n", fname);
	fin = fopen(fname, "rb");
	if (!fin) {
		printf("can't open %s for reading\n", fname);
	}
	cexd = (CEXData*)emalloc(sizeof(CEXData));
	pointer = (double) ((unsigned long)cexd);
	fread(cexd->header, 1024, 1, fin);
	cexd->data = 0;
	if (get_parm(1, cexd->header) != 1.) {
		header_endian(cexd->header);
		endian = 1;
	}
	if (get_parm(1, cexd->header) != 1.) {
		printf("%s is not a CLAMPEX file\n", fname);
	}
	samples = (int)get_parm(3, cexd->header);
	episodes = (int)get_parm(4, cexd->header);
	cexd->data = (short*)emalloc(samples*episodes*sizeof(short));
	fread(cexd->data, samples*episodes, sizeof(short), fin);
	fclose(fin);
	if (endian) {
		int i;
		for (i=0; i < samples*episodes; ++i) {
			reverse((char*)(cexd->data + i), 2);
		}
	}
	ENDVERBATIM
}


DESTRUCTOR {
	VERBATIM
	CEXD
	if (cexd->data) {
		free(cexd->data);
	}
	free(cexd);
	ENDVERBATIM
}

FUNCTION parm() {
	VERBATIM
	CEXD
	int i;
	i = (int)chkarg(1, 1., 160.);
	_lparm = get_parm(i, cexd->header);
	ENDVERBATIM
}

PROCEDURE datavec() {
	VERBATIM
	int ntrace, trace, i;
	double* pd, *hoc_pgetarg();
	short* tr;
	CEXD
	ntrace = (int)get_parm(3, cexd->header)*(int)get_parm(4, cexd->header);
	trace = (int)chkarg(1, 0., (double)(ntrace - 1));
	tr = cexd->data + 512*trace;
	pd = hoc_pgetarg(2);
	for (i = 0; i < 512; ++i) {
		pd[i] = (double)tr[i];
	}
	ENDVERBATIM
}

FUNCTION timestep() {
	VERBATIM
	CEXD
	_ltimestep = get_parm(14, cexd->header)*.001;
	ENDVERBATIM
}

FUNCTION gain() {
	VERBATIM
	CEXD
	_lgain = get_parm(113, cexd->header);
	ENDVERBATIM
}

PROCEDURE get_comment() {
	VERBATIM
	char buf[80];
	CEXD
	strncpy(buf, cexd->header + 320, 77);
	buf[77] = '\0';
	printf("%s\n", buf);
	ENDVERBATIM
}
PROCEDURE get_label() {
	VERBATIM
	char buf[80];
	CEXD
	int i = (int)chkarg(1, 1., 5.);
	strncpy(buf, cexd->header + (320 + 77  +(i-1)*16), 16);
	buf[16] = '\0';
	printf("%s\n", buf);
	ENDVERBATIM
}
PROCEDURE get_cpulse() {
	VERBATIM
	char buf[80];
	CEXD
	strncpy(buf, cexd->header + 320 + 77 + 80 + 35, 64);
	buf[64] = '\0';
	printf("%s\n", buf);
	ENDVERBATIM
}
PROCEDURE get_adcunit() {
	VERBATIM
	char buf[80];
	CEXD
	int i = (int)chkarg(1, 1., 16.);
	strncpy(buf, cexd->header + (320 + 77 + 80 + 35 + 6*64 + (i-1)*8), 8);
	buf[8] = '\0';
	printf("%s\n", buf);
	ENDVERBATIM
}

