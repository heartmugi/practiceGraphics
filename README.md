# Usage
## To make object file
```
make pdbInfoPrint
```

## To show PDB datas
```
make test-pdbInfoPrint
```

### To show datas you want
```
mode: [input number]
```
1:  α炭素の中心座標

2:  α炭素の最大半径

4:  α炭素の最小座標

8:  α炭素の最大座標

16: α炭素の残基名とその数

32: α炭素の元素とその数

欲しい情報の組み合わせを決め、上の表から対応する数字の合計を求めてターミナルに入力する。

例：　α炭素の最小座標(4)と最大座標(8)が欲しい時
```
mode: 12
```
