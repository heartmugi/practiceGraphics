#ifndef PDB_H  // PDB_Hが定義されていないときendifまでのコードが意味がある
#define PDB_H  // PDB_Hを定義する

/* 構造体 */
typedef struct Atom Atom;
struct Atom{    // 構造体の型宣言
  float x;
  float y;
  float z; // 今回は用いないが、将来の３Ｄ座標のために宣言しておく
  /* 拡張部分 */
  char resName[4];     // 残基名（3文字表記）を格納
  int resNumber;       // 残基番号を格納
  float tempFactor;    // 温度因子を格納
  float occupancy;     // 占有度を格納
  char atomName[5];    // 原子名を格納
  char element[3];     // 元素記号を格納
};
typedef struct Bond Bond;
struct Bond{
  Atom start;
  Atom end;
};
typedef struct arrayPDB arrayPDB;
struct arrayPDB{
  int numAtom;    // ATOMで指定された原子の個数
  int numCAAtom;  // α炭素の数（点の数）
  Atom *CA;       // α炭素の点の座標(x, y, z)
};
typedef struct recordPDB recordPDB;
struct recordPDB{
  Atom atom;               // 原子の座標
  recordPDB* nextAtom;    // 次のATOMへのポインタ
  recordPDB* nextCA;      // 次のCAへのポインタ
};
typedef struct Res Res;
struct Res{
  char name[4];
  int count;
};
typedef struct Element Element;
struct Element{
     char name[3];
     int count;
};
typedef struct Kind Kind;
struct Kind{
  Res res[21];
  Element ele[6];
  int resNum;
  int eleNum;
};
typedef struct PDB PDB;
struct PDB{
  int numAtom;           // 原子の個数
  int numCA;             // CAの個数
  recordPDB* top;        // 先頭の原子
  recordPDB* topCA;      // 先頭のCA
  recordPDB* current;    // 現在の原子
  recordPDB* currentCA;  // 現在のCA原子
  /* 拡張部分 */
  Atom Center;           // 分子中心の座標を挿入
  float maxRadius;       // 中心から最も遠い原子までの距離を格納
  Atom min;              // x,y,z座標のうち、それぞれの座標の最小値を格納
  Atom max;              // x,y,z座標のうち、それぞれの座標の最大値を格納
  Kind kind;             // 残基の種類のカウント
};
  

/* プロトタイプ宣言 */
extern void bondDraw(FILE* fpt, float startx, float starty, float endx, float endy);
extern void bondDraw2(FILE* fpt, Bond l);
extern int arrayPDBRead(FILE *fpt, arrayPDB *pdb);
extern void bondCADraw(FILE *fpt, arrayPDB pdb);
extern void bondCADraw_1(FILE *fpt, arrayPDB pdb, float originx, float originy, float scale);
extern int pdbRead(FILE* fpt, PDB *pdb);
extern void bondCADraw2(FILE *fpt, PDB *pdb);
extern void bondCADraw2_1(FILE *fpt, PDB *pdb, float originx, float originy, float scale);
extern void lpdbCenterCalc(PDB* pdb);
extern void lpdbSizeCalc(PDB* pdb);
extern void lpdbMinCalc(PDB* pdb);
extern void lpdbMaxCalc(PDB* pdb);
extern void lpdbInfoPrint(FILE* fpt, PDB *pdb, int mode);
extern void lpdbResCount(PDB* pdb);
extern void lpdbEleCount(PDB* pdb);


#endif  // #ifnedfや#ifdefを閉じる
