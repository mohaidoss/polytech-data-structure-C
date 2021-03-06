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

void charger_graphe(struct Sommet* g, FILE* fic,int* n){
	fscanf(fic,"%d",n);
	g = init_graphe(*n);
	int s1,s2;
	while(fscanf(fic,"%d%d",&s1,&s2) != EOF)
		ajout_succ(g,s1,s2);
}
struct liste_int* liste_succ(struct Sommet* g,int s){
	return g[s].succ;
}
void clear_graphe(struct Sommet* g, int size){
	int i;
	for(i=0;i<size;i++){
		clear_liste_int(g[i].succ);
	}
	free(g);
}
