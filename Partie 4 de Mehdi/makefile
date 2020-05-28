CC=gcc
CFLAGS=-g -Wall -Wmissing-prototypes
LDFLAGS=-g
objects := $(patsubst %.c,%.o,$(wildcard *.c))
all: chemin
clean:
	-rm $(objects)
	-rm chemin
chemin: $(objects)
# gcc -MM *.c pour obtenir les deux lignes ci-dessous
graphe.o: graphe.c graphe.h liste_int.h
liste_int.o: liste_int.c liste_int.h
chemin.o: chemin.c graphe.h liste_int.h
