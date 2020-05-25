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
		g[i].succ = (struct liste_int*)0;
	}
	return g;
}

void ajout_succ(struct Sommet* g, int s1, int s2){
	if(g[s1].succ == (struct liste_int*)0){
		struct liste_int* nvarc = malloc(sizeof(struct liste_int));
		init_liste_int(nvarc);
		ajout_en_queue_liste_int(nvarc,s2);
		g[s1].succ = nvarc;
	}
	else	ajout_en_queue_liste_int(g[s1].succ,s2);
}

void afficher_graphe(struct Sommet* g,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d : ",g[i].valeur);
		if (g[i].succ != ((struct liste_int*)0)) {
		    print_liste_int(g[i].succ);
		}
		else {
		    printf("[ ]\n");
		}
	}
}

void clear_graphe(struct Sommet* g, int size){
	int i;
	for(i=0;i<size;i++){
		clear_liste_int(g[i].succ);
	}
	free(g);
}
