#include <stdio.h>
#include "PDB.h"

void bondDraw2(FILE* fpt, Bond l){
  fprintf(fpt, "%f %f moveto\n", l.start.x, l.start.y);
  fprintf(fpt, "%f %f lineto\n", l.end.x, l.end.y);
  fprintf(fpt, "stroke\n");
}
