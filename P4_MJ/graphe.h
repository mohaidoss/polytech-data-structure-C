#include "liste_int.h"

//Définition des structures sommet et graphe
struct sommet
{
	int num;
	struct liste_int* succ;
};

struct graphe
{
	int nb_sommets;
	struct sommet* tab;
};

//Constructeur
void init_graphe (int taille,struct graphe*);
//Ajouter à un sommet donné un successeur donné
void ajout_succ (struct graphe*, int prec, int suc);
//Afficher le graphe sur la sortie standard
void afficher_graphe (struct graphe*);
//Algorithme parcours en largeur qui renvoie une liste et un booléen
void parcours_larg(struct graphe*,int,int,struct liste_int*,int*);
//Retourne la liste des succeeseurs dun sommet
struct liste_int* liste_succ(struct graphe*,int);
//Charge le graphe a partir de charger-graphe.txt
void charger_graphe(struct graphe*,FILE* fic);
//Destructeur
void clear_graphe(struct graphe*);
