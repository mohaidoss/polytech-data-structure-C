#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N=7;
	struct Sommet** graphe = init_graphe(N);
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
}
