#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main(){
	struct graphe G;
	FILE* fic;
	fic = fopen("charge_graphe.txt","r");
	charger_graphe(&G,fic);
	fclose(fic);
	afficher_graphe(&G);
	printf("Saisissez les 2 sommets dont vous voulez le chemin :");
	int s1,s2;
	scanf("%d%d",&s1,&s2);
	struct liste_int* chemin;
	parcours_larg(&G,s1,s2);
	clear_graphe(&G);

}
