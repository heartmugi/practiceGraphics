#include <stdio.h>
#include "PDB.h"

extern void bondCADraw2_1(FILE *fpt, PDB *pdb, float originx, float originy, float scale){
  int i;

  fprintf(fpt, "%s PS-Adobe-3.0\n", "%!");
  fprintf(fpt, "%f %f translate\n", originx, originy);
  fprintf(fpt, "%f %f scale\n", scale, scale);
  /* 初期化 */
  pdb->currentCA = pdb->topCA;
  i=0;
  /* 書き込み */
  while(pdb->currentCA != NULL){
    if(i == 0){
      fprintf(fpt, "%8.3f %8.3f moveto\n", pdb->currentCA->atom.x, pdb->currentCA->atom.y);
    } else {
      fprintf(fpt, "%8.3f %8.3f lineto\n", pdb->currentCA->atom.x, pdb->currentCA->atom.y);
    }
    pdb->currentCA = pdb->currentCA->nextCA;
    i++;
  }
  fprintf(fpt, "stroke\n");
  fprintf(fpt, "showpage\n");
}
