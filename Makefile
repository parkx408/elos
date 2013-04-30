CXX = g++
CC = gcc

CFLAGS = -g -Wall -fopenmp

LDFLAGS =

PROGRAMS = csim

SRCS = main.c lru_stack.c red_black_tree.c hash_table.c

OBJS = $(subst .c,.o,$(SRCS))

all: $(PROGRAMS)

csim: $(OBJS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) -o csim $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^>>./.depend

clean:
	rm $(OBJS) $(PROGRAMS)

include .depend
