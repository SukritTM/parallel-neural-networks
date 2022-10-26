all:
	gcc -c matrix.c
	gcc -c mlp.c
	gcc -c funcs.c -lm

matrix:
	gcc -c matrix.c

matrix-test:
	gcc -c matrix-test.c
	gcc matrix-test.o matrix.o -o matrix-test.out
	./matrix-test.out

mlp:
	gcc -c mlp.c

mlp-test:
	gcc -c mlp-test.c
	gcc mlp-test.o mlp.o matrix.o -o mlp-test.out
	./mlp-test.out

funcs:
	gcc -c funcs.c -lm

funcs-test:
	gcc -c funcs-test.c
	gcc -lm funcs-test.o funcs.o matrix.o -o funcs-test.out
	./funcs-test.out