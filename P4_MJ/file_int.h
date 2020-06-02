#include "liste_int.h"

//Définition de la structure file_int
struct file_int
{
    struct liste_int L;
};

//Constructeur
void init_file_int (struct file_int*);
//Fonction qui détermine si la file est vide et renvoie un booléen 1 ou 0
int est_vide_file_int (struct file_int*);
//Fonctions pour enfiler et defiler la file
void enfiler_int (struct file_int*, int);
void defiler_int (int *, struct file_int*);
//Afficher la file
void imprimer_file_int(struct file_int*);
//Destructeur
void clear_file_int(struct file_int*);
