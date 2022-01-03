#include <stdio.h>
#include "PDB.h"

extern void bondCADraw2(FILE *fpt, PDB *pdb){
  int i;

  fprintf(fpt, "%s PS-Adobe-3.0\n", "%!");
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
