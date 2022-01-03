#include <stdio.h>
#include "PDB.h"

void lpdbInfoPrint(FILE* fpt, PDB* pdb, int mode){
  int i;

  if((mode>>0)&1) fprintf(fpt, "center: %.3f, %.3f, %.3f\n", pdb->Center.x, pdb->Center.y, pdb->Center.z);

  if((mode>>1)&1) fprintf(fpt, "maxRadius: %.3f\n", pdb->maxRadius);

  if((mode>>2)&1) fprintf(fpt, "min: %.3f, %.3f, %.3f\n", pdb->min.x, pdb->min.y, pdb->min.z);

  if((mode>>3)&1) fprintf(fpt, "max: %.3f, %.3f, %.3f\n", pdb->max.x, pdb->max.y, pdb->max.z);

  if((mode>>4)&1){
    for(i=0; i<pdb->kind.resNum; i++){
      fprintf(fpt, "%.4s: %d\n",pdb->kind.res[i].name, pdb->kind.res[i].count);
    }
  }

  if((mode>>5)&1){
    for(i=0; i<pdb->kind.eleNum; i++){
      fprintf(fpt, "%.4s: %d\n",pdb->kind.ele[i].name, pdb->kind.ele[i].count);
    }
  }
}
