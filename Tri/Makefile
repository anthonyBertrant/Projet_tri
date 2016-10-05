# Makefile pour UE SIN5U3 "Reseau et Communication"
#
# 23/10/2013 - Edouard.Thiel@lif.univ-mrs.fr

SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99 -pedantic
LIBS   =

# Rajouter le nom des executables apres '=', separes par un espace.
# Si une ligne est pleine, rajouter '\' en fin de ligne et passer a la suivante.

# pour compiler sans bor-util.c
EXECS = 

# pour compiler avec bor-util.c
EXECSUTIL = 

# pour compiler avec bor-util.c et bor-timer.c
EXECSTIMER = 


.c.o :
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options du make : help all clean distclean"

all :: $(EXECS) $(EXECSUTIL) $(EXECSTIMER)

$(EXECS) : %: %.o
	$(CC) -o $@ $@.o $(LIBS)

$(EXECSUTIL) : %: %.o bor-util.o
	$(CC) -o $@ $@.o bor-util.o $(LIBS)

$(EXECSTIMER) : %: %.o bor-util.o bor-timer.o
	$(CC) -o $@ $@.o bor-util.o bor-timer.o $(LIBS)

clean ::
	\rm -f *.o core

distclean :: clean
	\rm -f *% $(EXECS) $(EXECSUTIL) $(EXECSTIMER)

