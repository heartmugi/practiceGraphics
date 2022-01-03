#include <stdio.h>
#include<math.h>
#include "PDB.h"
     
void lpdbSizeCalc(PDB* pdb){
  float r;
  pdb->current=pdb->top;
  pdb->maxRadius=-1;
     
  while(pdb->current!=NULL){
    r = sqrt(pow(pdb->current->atom.x - pdb->Center.x, 2) + pow(pdb->current->atom.y - pdb->Center.y, 2) + pow(pdb->current->atom.z - pdb->Center.z, 2));
    if(pdb->maxRadius < r){
      pdb->maxRadius = r;
    }
    pdb->current=pdb->current->nextAtom;
  }
}
