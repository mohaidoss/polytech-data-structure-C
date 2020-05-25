#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graphe.h"

static void init_sommets(struct sommet* tab,int taille){
	int i;
	for(i=0;i<taille;i++){
		tab[i].num = i;
		tab[i].succ = (struct liste_int*)0;
	}
}

void init_graphe (int taille,struct graphe* G){
	G->nb_sommets = taille;
	G->tab = malloc(taille*sizeof(struct sommet));
	assert(G!=NULL);
	init_sommets(G->tab,taille);
}

void ajout_succ(struct graphe* G,int prec,int suc){
	//On sait qu'il faut le rajouter dans tab[prec]
	if ((G->tab[prec]).succ != (struct liste_int*)0){
		//Si le sommet a déjà des successeurs
		ajout_en_queue_liste_int((G->tab[prec]).succ,suc);	
	}
	else{
		//Si le sommet n'a pas de succeseuts
		struct liste_int* succ;
		init_liste_int(succ);
		ajout_en_queue_liste_int(succ,suc);
		(G->tab[prec]).succ = succ;
	}
}

void afficher_graphe(struct graphe* G){
	int taille = G->nb_sommets;
	int i;
	for (i=0;i<taille;i++){
		printf("%d\t: ",(G->tab[i]).num);
		if (est_vide_liste_int((G->tab[i]).succ)){
			//Il n'aya pas de successeurs
			printf("[\t]\n");
		}
		else{
			//Il ya des succ
			print_liste_int((G->tab[i]).succ);
		}
	}
}

void charger_graphe(struct graphe* G,FILE* fic){
	int nb_sommets;
	fscanf(fic,"%d",&nb_sommets);
	init_graphe(nb_sommets,G);
	int prec;
	int succ;
	while (fscanf(fic,"%d%d",&prec,&succ)!=E0F){
		ajout_succ(G,prec,succ);
	}
}


void clear_graphe(struct graphe* G){
	int taille = G->nb_sommets;
	int i;
	for (i=0;i<taille;i++){
		clear_liste_int((G->tab[i]).succ);
	}
	free(G->tab);
	free(G);
}

