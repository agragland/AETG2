#Makefile for CSCE 3600 Major 2
#Group-14

PROG = aetg2
OBJS = PairMap.o main.o
EXT = PairMap.h
FLAGS = -O3

$(PROG) : $(OBJS)
	g++ -o $(PROG) $(OBJS)

PairMap.o : $(EXT)
	g++ $(FLAGS) PairMap.c

clean :
	rm -f core $(PROG) $(OBJS)
