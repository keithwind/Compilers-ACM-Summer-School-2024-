#PARSE= left-recursion-removed
PARSE= exp1
SCAN = exp

$(PARSE): lex.yy.o y.tab.o
	gcc -o $(PARSE) lex.yy.o y.tab.o -ly -ll

y.tab.o y.tab.h: $(PARSE).y
	yacc -dv $(PARSE).y
	gcc -c y.tab.c

lex.yy.o : $(SCAN).l y.tab.h
	lex $(SCAN).l
	gcc -c lex.yy.c

clean:
	rm -f *.o lex.yy.* *.tab.c y.output exp? a.out $(PARSE)
