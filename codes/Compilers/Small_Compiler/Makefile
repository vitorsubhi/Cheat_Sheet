CC=gcc
TARGET=parser
SOURCE=src

CS=$(patsubst %.cpp,%.o,$(wildcard ${SRC}/*.c))
YACS=$(patsubst %.y,%_y.o,$(wildcard ${SRC}/*.y))
LEXS=$(patsubst %.l,%_l.o,$(wildcard ${SRC}/*.l))

parser: lex.yy.c Language.tab.h $(SOURCE)/main.c
	$(CC) -obuild/$(TARGET) Language.tab.c lex.yy.c $(SOURCE)/main.c
Language.tab.h: ${YACS}
	bison -d $(SOURCE)/Language.y
lex.yy.c: ${LEXS} Language.tab.h
	flex $(SOURCE)/Language.l
clean: 
	rm -f Language.tab.h Language.tab.c lex.yy.c build/$(TARGET)
test:
	./build/$(TARGET) Sample