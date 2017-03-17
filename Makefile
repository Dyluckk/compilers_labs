##**************************************
## Makefile
##
## Build routine for lang compiler
##
## Author: Phil Howard
## zachary.wentworth@oit.edu
##
## Date: Jan. 18, 2016
##

COPTS=-Wall -g -c  -O0 -std=c++11
OBJS=main.o \
	 langlex.o \
	 langparse.o \
	 cVisitor.o \
	 cSymbolTable.o \
	 emit.o	\

all: lang

clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f langparse.c
	rm -f langparse.h
	rm -f lang
	rm -f out
	rm -f out.xml
	rm -f out2.xml
	rm -f langout.sl
	rm -f langout.slb

.cpp.o:
	g++ $(COPTS) $? -o $@

.c.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langparse.c langlex.c
	g++ $(COPTS) main.cpp -o $@

## added -Wno-deprecated-register to remove register warning errors when building on my local machine
langlex.o: langlex.cpp
	g++ $(COPTS) -Wno-sign-compare -Wno-deprecated-register $? -o $@

langlex.c: lang.l langparse.c
	flex -o langlex.c lang.l

langparse.c: lang.y
	bison --defines=langparse.h lang.y -o langparse.c

lang: $(OBJS)
	g++ $(OBJS) -o lang
