#include <stdio.h>
#include "PDB.h"

extern void bondCADraw_1(FILE *fpt, arrayPDB pdb, float originx, float originy, float scale){
  int i;

  fprintf(fpt, "%s PS-Adobe-3.0\n", "%!");
  fprintf(fpt, "%f %f translate\n", originx, originy);
  fprintf(fpt, "%f %f scale\n", scale, scale);
  for(i=0; i<pdb.numCAAtom; i++){
    if(i == 0){
      fprintf(fpt, "%8.3f %8.3f moveto\n", pdb.CA[i].x, pdb.CA[i].y);
    } else {
      fprintf(fpt, "%8.3f %8.3f lineto\n", pdb.CA[i].x, pdb.CA[i].y);
    }
  }
  fprintf(fpt, "stroke\n");
  fprintf(fpt, "showpage\n");
}
