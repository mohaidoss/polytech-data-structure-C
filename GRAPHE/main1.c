#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
//V1
	int N=7;
	struct Sommet* graphe = init_graphe(N);
	ajout_succ(graphe,0,1);
	ajout_succ(graphe,0,2);
	ajout_succ(graphe,1,5);
	ajout_succ(graphe,1,0);
	ajout_succ(graphe,2,0);
	ajout_succ(graphe,2,4);
	ajout_succ(graphe,3,2);
	ajout_succ(graphe,4,5);
	ajout_succ(graphe,4,6);
	ajout_succ(graphe,5,6);
	afficher_graphe(graphe,N);
	clear_graphe(graphe,N);
//V2
	FILE* source;
	char nom_source[255];
	printf("Saisissez le nom du fichier\n");
	scanf("%s",nom_source);
	source = fopen(nom_source,"r");
	
	charger_graphe(graphe,source,&N);
	afficher_graphe(graphe,N);
//test de la fonction qui retourne la liste des succ
	print_liste_int(liste_succ(graphe,4));
	
	clear_graphe(graphe,N);
	
}
