all: test_libs

test_libs: test_libs.c stack.c mymath.c types.c nextword.c countlines.c
	gcc -std=c99 -o test_libs test_libs.c stack.c mymath.c types.c nextword.c countlines.c

clean:
