#include <stdio.h>
#include <stdlib.h>
#include "PDB.h"

int main(int argc, char *argv[]){
  FILE *fp;
  Bond l;

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
  
  /* 座標入力 */
  l.start.x = atof(argv[2]);
  l.start.y = atof(argv[3]);
  l.end.x = atof(argv[4]);
  l.end.y = atof(argv[5]);

  /* 書き込み部分 */
  fprintf(fp, "%s PS-Adobe-3.0\n", "%!");
  bondDraw2(fp, l);
  fprintf(fp, "showpage\n");
  fclose(fp);

  return 0;
}
