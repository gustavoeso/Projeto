all: productivitylang

productivitylang: productivitylang.l productivitylang.y
	bison -d productivitylang.y
	flex productivitylang.l
	gcc -o productivitylang productivitylang.tab.c lex.yy.c -lfl

clean:
	rm -f productivitylang productivitylang.tab.c productivitylang.tab.h lex.yy.c
