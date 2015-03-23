all: countlines nextword mystring

countlines: countlines.c test_countlines.c
	clang -std=c99 -g -o countlines_test countlines.c test_countlines.c

nextword: nextword.c test_nextword.c
	clang -std=c99 -g -o nextword_test nextword.c test_nextword.c

mystring: mystring.c test_mystring.c
	clang -std=c99 -g -o mystring_test mystring.c test_mystring.c
