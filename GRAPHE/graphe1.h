#include "liste_int.h"
#include <stdio.h>

struct Sommet
{
	int valeur;
	struct liste_int* succ;
};

struct Sommet* init_graphe(int);
void ajout_succ(struct Sommet*, int, int);
void afficher_graphe(struct Sommet*,int );
void charger_graphe(struct Sommet*,FILE*,int*);
struct liste_int* liste_succ(struct Sommet*,int);
void clear_graphe(struct Sommet*, int);
