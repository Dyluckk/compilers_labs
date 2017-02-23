##**************************************
## Makefile
##
## Build routine for lang compiler
##
## Author: Phil Howard 
## phil.howard@oit.edu
##
## Date: Jan. 18, 2015
##

COPTS=-Wall -g -c  -O0 -std=c++11
OBJS=main.o \
	 langlex.o \
	 langparse.o \
	 cVisitor.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f langparse.cpp
	rm -f langparse.h
	rm -f lang
	rm -f out.xml
	rm -f out2.xml

.cpp.o:
	g++ $(COPTS) $< -o $@

.c.o:
	g++ $(COPTS) $< -o $@

main.o: main.cpp langparse.cpp langlex.cpp 
	g++ $(COPTS) main.cpp -o $@

## added -Wno-deprecated-register to remove register warning errors when building on my local machine
langlex.o: langlex.cpp
	g++ $(COPTS) -Wno-sign-compare -Wno-deprecated-register $? -o $@

langlex.cpp: lang.l langparse.cpp
	flex -o langlex.cpp lang.l

langparse.cpp: lang.y
	bison --defines=langparse.h lang.y -o langparse.cpp

lang: $(OBJS)
	g++ $(OBJS) -o lang

