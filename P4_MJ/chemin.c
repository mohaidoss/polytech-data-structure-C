#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main(){
	struct graphe G;
	//On commence par charger le graphe depuis charge_graphe.txt
	FILE* fic;
	fic = fopen("charge_graphe.txt","r");
	charger_graphe(&G,fic);
	fclose(fic);
	//On laffiche
	afficher_graphe(&G);
	//On determine sil existe un chemin entre 2 sommets donnes
	printf("Saisissez les 2 sommets dont vous voulez le chemin :");
	int s1,s2;
	scanf("%d%d",&s1,&s2);
	struct liste_int chemin;
	init_liste_int(&chemin);
	int trouve = 0;
	parcours_larg(&G,s1,s2,&chemin,&trouve);
	if (trouve == 0)
		printf("Pas de chemin !\n");
	else
		print_liste_int(&chemin);
	clear_graphe(&G);
	clear_liste_int(&chemin);

}
