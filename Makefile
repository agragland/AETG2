#Makefile for CSCE 3444 - AETG Algorithm - Andrew Ragland

PROG = aetg2_agr
OBJS = PairSet.o main.o
SRCS = PairSet.cpp main.cpp
EXT = PairSet.h

$(PROG) : $(OBJS)
	g++ -O3 -o $(PROG) $(OBJS)

$(OBJS) : $(SRCS) $(EXT)
	g++ -O3 -c $(SRCS)

clean :
	rm -f core $(PROG) $(OBJS)
