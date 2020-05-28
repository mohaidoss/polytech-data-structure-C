#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
//V1
//V2
	int N;
	struct Sommet* graphe;
	FILE* source;
	char nom_source[255];
	printf("Saisissez le nom du fichier\n");
	scanf("%s",nom_source);
	source = fopen(nom_source,"r");
		
	graphe = charger_graphe(source,&N);
	afficher_graphe(graphe,N);
//test de la fonction qui retourne la liste des succ
	print_liste_int(liste_succ(graphe,4));
	
//Parcours en largeur
	int deb,fin;
	printf("Saisissez le sommet de départ ");
	scanf("%d",&deb);
	printf("Saisissez le sommet d'arrivé ");
	scanf("%d",&fin);
	struct liste_int* chemin = parcours_en_largeur(graphe,N,deb,fin);
	if(est_vide_liste_int(chemin))
		printf("\nPas de chemin.");
	else
		print_liste_int(chemin);
	clear_graphe(graphe,N);
	
}
