#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graphe.h"

static void init_sommets(struct sommet* tab,int taille){
	int i;
	for(i=0;i<taille;i++){
		tab[i].num = i;
		tab[i].succ = malloc(sizeof(struct liste_int));
		init_liste_int(tab[i].succ);
	}
}

void init_graphe (int taille,struct graphe* G){
	G->nb_sommets = taille;
	G->tab = malloc(taille*sizeof(struct sommet));
	assert(G!=NULL);
	init_sommets(G->tab,taille);
}

void ajout_succ(struct graphe* G,int prec,int suc){
	ajout_en_queue_liste_int((G->tab[prec]).succ,suc);	
}

void afficher_graphe(struct graphe* G){
	int taille = G->nb_sommets;
	int i;
	for (i=0;i<taille;i++){
		printf("%d\t:\t ",(G->tab[i]).num);
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
	while (fscanf(fic,"%d%d",&prec,&succ)!=EOF){
		ajout_succ(G,prec,succ);
	}
}

void parcours_larg(struct graphe* G,int s1,int s2){
	int taille = G->nb_sommets;
	int mark[taille];
	int i,sommet;
	//Initialisation
	struct liste_int* exploration = (struct liste_int*)malloc(sizeof(struct liste_int));
	init_liste_int(exploration);
	for (i=0;i<taille;i++){
		mark[i]=0;
	}
	mark[s1]=1;
	ajout_en_queue_liste_int(exploration,s1);
	//Traitement
	struct maillon_int* M;
	while(!est_vide_liste_int(exploration)){
		print_liste_int(exploration);
		extraire_en_tete_liste_int(exploration,&sommet);
		struct liste_int* successeurs = liste_succ(G,sommet);
		int nb_succ = successeurs->nbelem;
		M = successeurs->tete;
		for (i=0; i<nb_succ;i++){
			int sommet_voisin;
			if (mark[M->value] == 0){
				mark[M->value] = 1;
				ajout_en_queue_liste_int(exploration,M->value);
			}
			if (M->value == s2){
				printf("BBINOGO\n");
			}
			M = M->next;
		}
	}
	clear_liste_int(exploration);
	free(exploration);
}

struct liste_int* liste_succ(struct graphe* G,int num){
	return ((G->tab[num]).succ);
}

void clear_graphe(struct graphe* G){
	int taille = G->nb_sommets;
	int i;
	for (i=0;i<taille;i++){
		clear_liste_int((G->tab[i]).succ);
		free((G->tab[i]).succ);
	}
	free(G->tab);
}

