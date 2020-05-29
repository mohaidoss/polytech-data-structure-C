#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main(){
	//Version 1
	int taille = 5;
	struct graphe G;
	init_graphe(taille,&G);
	ajout_succ(&G,0,1);
	ajout_succ(&G,4,2);
	ajout_succ(&G,1,0);
	ajout_succ(&G,4,3);
	afficher_graphe(&G);
	clear_graphe(&G);
	//Version 2
	FILE* fic;
	fic = fopen("charge_graphe.txt","r");
	charger_graphe(&G,fic);
	fclose(fic);
	afficher_graphe(&G);
	clear_graphe(&G);
}
