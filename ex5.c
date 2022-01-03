#include <stdio.h>
#include <stdlib.h>
#include "PDB.h"

int main(int argc, char *argv[]){
  FILE *fp, *fo;
  PDB *pdb;

  /* 初期化 */
  pdb = (PDB*)malloc(sizeof(PDB));
  recordPDB top_dummy;
  recordPDB topCA_dummy;
  pdb->top = &top_dummy;
  pdb->topCA = &topCA_dummy;

  /* コマンドラインのエラー */
  if(argc != 3){
    printf("コマンドライン引数が誤っています\n");
    exit(1);
  }

  /* 保存ファイル指定エラー */
  if(NULL==(fp=fopen(argv[1],"r"))){
    printf("fopen error!\n");
    exit(1);
  }
  if(NULL==(fo=fopen(argv[2],"w"))){
    printf("fopen error!\n");
    exit(1);
  }


  /* 書き込み部分 */
  pdbRead(fp, pdb);
  bondCADraw2(fo, pdb);
  fclose(fp);
  fclose(fo);


  return 0;
}
