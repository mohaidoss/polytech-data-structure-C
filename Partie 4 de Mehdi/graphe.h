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
struct Sommet* charger_graphe(FILE*,int*);
struct liste_int* liste_succ(struct Sommet*,int);
struct liste_int* parcours_en_largeur(struct Sommet*, int, int, int);
void clear_graphe(struct Sommet*, int);
