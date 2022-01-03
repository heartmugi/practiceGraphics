#include <stdio.h>
#include <stdlib.h>
#include "PDB.h"

int main(int argc, char *argv[]){
  FILE *fp, *fo;
  arrayPDB pdb;

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
  arrayPDBRead(fp, &pdb);
  bondCADraw(fo, pdb);
  fclose(fp);
  fclose(fo);


  return 0;
}
