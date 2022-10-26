all:
	gcc -c matrix.c
	gcc -c mlp.c

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