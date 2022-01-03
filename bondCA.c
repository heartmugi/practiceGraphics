#include <stdio.h>
#include "PDB.h"

extern void bondCADraw(FILE *fpt, arrayPDB pdb){
  int i;

  fprintf(fpt, "%s PS-Adobe-3.0\n", "%!");
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
