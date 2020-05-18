#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "file_int.h"

void init_file_int (struct file_int* F){
	F->L = (struct liste_int*)0;
}

int est_vide_file_int (struct file_int* F){
	//est_vide_liste_int(&(F->L));
	return F->L == (struct liste_int*)0;
}

void enfiler_int (struct file_int* F, int v){
	ajout_en_queue_liste_int (F->L, v);
}

void defiler_int (int* v, struct file_int* F){
	extraire_en_tete_liste_int (F->L, v);
}

void imprimer_file_int(struct file_int* F){
	print_liste_int(F->L);
}

void clear_file_int(struct file_int* F){
	clear_liste_int(F->L);
}
