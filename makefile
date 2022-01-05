.SUFFIXES: .c .o .a

-include "depend.inc"

SOURCE=bond.c \
	   bond2.c

.c.o:
	cc -Wall -g -c $*.c -o $*.o

all: pdbCenterCalc pdbSizeCalc pdbMinCalc pdbMaxCalc pdbInfoPrint7 pdbReadExtend pdbResCount pdbEleCount pdbInfoPrint


#課題3：分子中心（座標平均値）
pdbCenterCalc: pdbCenterCalc.o lpdbCenterCalc.o pdbRead.o
	cc -Wall $@.o lpdbCenterCalc.o pdbRead.o -o $@ -lm 
#課題4：座標中心から一番遠い原子までの距離（半径）
pdbSizeCalc: pdbSizeCalc.o lpdbSizeCalc.o lpdbCenterCalc.o pdbRead.o
	cc $@.o lpdbSizeCalc.o lpdbCenterCalc.o pdbRead.o -o $@ -lm
#課題5：最小（x,y,zのそれぞれの最小値の値）
pdbMinCalc: pdbMinCalc.o lpdbMinCalc.o pdbRead.o
	cc $@.o lpdbMinCalc.o pdbRead.o -o $@ -lm
#課題6：最大（のそれぞれの最大の値）
pdbMaxCalc: pdbMaxCalc.o lpdbMaxCalc.o pdbRead.o
	cc $@.o lpdbMaxCalc.o pdbRead.o -o $@ -lm
#課題7：出力（課題３〜６での計算結果表示）
pdbInfoPrint7: pdbInfoPrint7.o lpdbInfoPrint.o lpdbCenterCalc.o lpdbSizeCalc.o lpdbMinCalc.o lpdbMaxCalc.o pdbRead.o
	cc $@.o lpdbInfoPrint.o lpdbCenterCalc.o lpdbSizeCalc.o lpdbMinCalc.o lpdbMaxCalc.o pdbRead.o -o $@ -lm
#課題8
pdbReadExtend: pdbReadExtend.o pdbRead.o
	cc $@.o pdbRead.o -o $@ -lm
#課題9：残基の種類（それぞれのアミノ酸の残基の種類と個数）
pdbResCount: pdbResCount.o lpdbResCount.o pdbRead.o
	cc $@.o lpdbResCount.o pdbRead.o -o $@ -lm
#課題10：元素の種類（それぞれの原子の元素の種類と個数）
pdbEleCount: pdbEleCount.o lpdbEleCount.o pdbRead.o
	cc $@.o lpdbEleCount.o pdbRead.o -o $@ -lm
#完成
pdbInfoPrint: pdbInfoPrint.o lpdbInfoPrint.o lpdbCenterCalc.o lpdbSizeCalc.o lpdbMinCalc.o lpdbMaxCalc.o lpdbResCount.o lpdbEleCount.o pdbRead.o
	cc $@.o lpdbInfoPrint.o lpdbCenterCalc.o lpdbSizeCalc.o lpdbMinCalc.o lpdbMaxCalc.o lpdbResCount.o lpdbEleCount.o pdbRead.o -o $@ -lm

# ------ ライブラリの作成
libBond.a: bond.o bond2.o
	ar rv $@ bond.o bond2.o   

# OR

libBond.a: $(SOURCE:.c=.o)
	ar rv $@ bond.o bond2.o   
# -----

 
#test: test-ex1 test-ex2 test-ex3 test-ex4 test-ex4-1 test-ex5 test-ex5-1
test: test-pdbCenterCalc test-pdbSizeCalc test-pdbMinCalc test-pdbMaxCalc test-pdbInfoPrint7 test-pdbReadExtend test-pdbResCount test-pdbEleCount test-pdbInfoPrint

test-ex1:
	./ex1 ex1.out 0 0 10 20	

test-ex2:
	./ex2 ex2.out 10 20 30 40

test-ex3:
	./ex3 ex3.out 10 20 30 40

test-ex4:
	./ex4 121p-GC.pdb ex4.ps

test-ex4-1:
	./ex4-1 121p-GC.pdb ex4-1.ps 400 400 10

test-ex5:
	./ex5 121p-GC.pdb ex5.ps

test-ex5-1:
	./ex5-1 121p-GC.pdb ex5-1.ps 300 300 5

depend::
	cc -M *.c > depend.inc

clean::
	rm *.o *.a ex1 ex2 ex3

test-pdbCenterCalc:
	./pdbCenterCalc 121p-GC.pdb

test-pdbSizeCalc:
	./pdbSizeCalc 121p-GC.pdb

test-pdbMinCalc:
	./pdbMinCalc 121p-GC.pdb

test-pdbMaxCalc:
	./pdbMaxCalc 121p-GC.pdb

test-pdbInfoPrint7:
	./pdbInfoPrint7 121p-GC.pdb test7.txt

test-pdbReadExtend:
	./pdbReadExtend 121p-GC.pdb

test-pdbResCount:
	./pdbResCount 121p-GC.pdb

test-pdbEleCount:
	./pdbEleCount 121p-GC.pdb

test-pdbInfoPrint:
	./pdbInfoPrint 121p-GC.pdb test.txt

# GIT
git-add:
	git add .

git-commit:
	git commit 

git-push:
	git push

git-fetch:
	git fetch

git-merge:
	git merge
