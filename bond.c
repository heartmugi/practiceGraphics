#include <stdio.h>
#include "PDB.h"

void bondDraw(FILE* fpt, float startx, float starty, float endx, float endy){
  fprintf(fpt, "%f %f moveto\n", startx, starty);
  fprintf(fpt, "%f %f lineto\n", endx, endy);
  fprintf(fpt, "stroke\n");
}
