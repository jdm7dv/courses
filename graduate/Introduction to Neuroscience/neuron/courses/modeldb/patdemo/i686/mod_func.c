#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," cad.mod");
    fprintf(stderr," ca.mod");
    fprintf(stderr," kca.mod");
    fprintf(stderr," km.mod");
    fprintf(stderr," kv.mod");
    fprintf(stderr," na.mod");
    fprintf(stderr, "\n");
  }
  _cad_reg();
  _ca_reg();
  _kca_reg();
  _km_reg();
  _kv_reg();
  _na_reg();
}
