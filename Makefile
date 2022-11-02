all:
	gcc -c matrix.c -fopenmp
	gcc -c mlp.c -fopenmp
	gcc -c funcs.c -lm -fopenmp

matrix:
	gcc -c matrix.c -fopenmp

matrix-test:
	gcc -c matrix-test.c
	gcc matrix-test.o matrix.o -o matrix-test.out -fopenmp
	./matrix-test.out

mlp:
	gcc -c mlp.c

mlp-test:
	gcc -c mlp-test.c
	gcc mlp-test.o mlp.o matrix.o -o mlp-test.out -fopenmp
	./mlp-test.out

funcs:
	gcc -c funcs.c -lm -fopenmp

funcs-test:
	gcc -c funcs-test.c -fopenmp
	gcc -lm funcs-test.o funcs.o matrix.o -o funcs-test.out -fopenmp
	./funcs-test.out

perceptron:
	gcc -c perceptron.c
perceptron-test:
	gcc -c perceptron-test.c
	gcc -l perceptron-test.o perceptron.o matrix.o funcs.o -o perceptron-test.out
	./perceptron-test.out

