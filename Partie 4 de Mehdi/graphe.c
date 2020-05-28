#include "graphe.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



struct Sommet* init_graphe(int size){
	struct Sommet* g = malloc(size*sizeof(struct Sommet));
	assert(g != NULL);
	int i;
	for(i=0;i<size;i++){
		g[i].valeur = i;
		g[i].succ = malloc(sizeof(struct liste_int));
		
	}
	return g;
}

void ajout_succ(struct Sommet* g, int s1, int s2){
	ajout_en_queue_liste_int(g[s1].succ,s2);
}

void afficher_graphe(struct Sommet* g,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d : ",g[i].valeur);
		print_liste_int(g[i].succ);
	}
}

struct Sommet* charger_graphe(FILE* fic,int* n){
	fscanf(fic,"%d",n);
	struct Sommet* g = init_graphe(*n);
	int s1,s2;
	while(fscanf(fic,"%d%d",&s1,&s2) != EOF)
		ajout_succ(g,s1,s2);
	return g;
}

struct liste_int* liste_succ(struct Sommet* g,int s){
	return g[s].succ;
}

struct liste_int* parcours_en_largeur(struct Sommet* g, int size, int s1,int s2){
	int mark[size];
	int i, trouver;
	//Initialisation des variables
	for(i=0;i<size;i++)
		mark[i]=0;
	mark[s1]=1;
	struct liste_int* chemin = (struct liste_int*)malloc(sizeof(struct liste_int));
	struct liste_int exploration;
	init_liste_int(chemin);
	init_liste_int(&exploration);
	ajout_en_queue_liste_int(&exploration,s1);
	ajout_en_queue_liste_int(chemin,s1);
	//Traitement 
	struct maillon_int* M;
	while(!(est_vide_liste_int(&exploration))){
		extraire_en_tete_liste_int(&exploration,&trouver);
		M = liste_succ(g,trouver)->tete;
		for(i=0; i<liste_succ(g,trouver)->nbelem;i++){
			if(mark[M->value] == 0){
				mark[M->value] = 1;
				ajout_en_queue_liste_int(&exploration,M->value);
				ajout_en_queue_liste_int(chemin,M->value);
			} 
			if(M->value == s2)
				return chemin;
			M = M->next;
		}
	}
	*chemin = exploration;
	return chemin;
}



void clear_graphe(struct Sommet* g, int size){
	int i;
	for(i=0;i<size;i++){
		clear_liste_int(g[i].succ);
	}
	free(g);
}
