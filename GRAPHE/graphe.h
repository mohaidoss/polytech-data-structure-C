#include "liste_int.h"

struct sommet
{
	int num;
	struct liste_int succ;
};

struct graphe
{
	int nb_sommets;
	struct sommet* tab;
};

void init_graphe (struct graphe*);
void ajout_succ (struct graphe*, int prec, int succ);
void afficher_graphe (struct graphe*);
void charger_graphe(struct graphe*);
void clear_graphe(struct graphe*);
