#include <stdio.h>
#include <stdlib.h>
#include "PDB.h"

int main(int argc, char *argv[]){
  FILE *fp;
  
  /* コマンドラインのエラー */
  if(argc != 6){
    printf("コマンドライン引数が誤っています\n");
    exit(1);
  }

  /* 保存ファイル指定エラー */
  if(NULL==(fp=fopen(argv[1],"w"))){
    printf("fopen error!\n");
    exit(1);
  }

  /* 書き込み部分 */
  fprintf(fp, "%s PS-Adobe-3.0\n", "%!");
  bondDraw(fp, atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]));
  fprintf(fp, "showpage\n");
  fclose(fp);

  return 0;
}
