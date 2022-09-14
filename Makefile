all:
	gcc matrixMulitplication.c -fopenmp -o matrixMulitplication.out
	./matrixMulitplication.out 4 0
	./matrixMulitplication.out 4 1
	./matrixMulitplication.out 4 2
	./matrixMulitplication.out 4 3
	./matrixMulitplication.out 4 4