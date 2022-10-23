all:
	gcc matrixMulitplication.c -fopenmp -o matrixMulitplication.out
	./matrixMulitplication.out 4 0
	./matrixMulitplication.out 4 1
	./matrixMulitplication.out 4 2
	./matrixMulitplication.out 4 3
	./matrixMulitplication.out 4 4

matrix:
	gcc -c matrix.c

matrix-test:
	gcc -c matrix-test.c
	gcc matrix-test.o matrix.o -o matrix-test.out
	./matrix-test.out

mlp:
	gcc -c mlp.c
	gcc mlp.o matrix.o -o mlp.out
	./mlp.out