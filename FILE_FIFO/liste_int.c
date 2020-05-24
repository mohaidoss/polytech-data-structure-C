#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "liste_int.h"

int est_vide_liste_int (struct liste_int* L){
	return L->nbelem==0;
}

void init_liste_int (struct liste_int* L)
{
    L->tete = (struct maillon_int*)0;
    L->queue = (struct maillon_int*)0;
    L->nbelem = 0;
}

void ajout_en_queue_liste_int (struct liste_int* L, int x)
{   struct maillon_int* nouveau;
    nouveau = (struct maillon_int*)malloc (sizeof (struct maillon_int));
    assert (nouveau != (struct maillon_int*)0);
/* appeler ici un �ventuel constructeur pour nouveau->value */
    nouveau->value = x;       /* affectation de la valeur */
    nouveau->next = (struct maillon_int*)0;
    if (!est_vide_liste_int(L)){
	    L->queue->next = nouveau;
	    L->queue = nouveau;
	    L->nbelem += 1;
	  }
    else{
	    L->tete = nouveau;
	    L->queue = nouveau;
	    L->nbelem += 1;
    }
}

void clear_liste_int (struct liste_int* L)
{   struct maillon_int* courant;
    struct maillon_int* suivant;
    int i;
    courant = L->tete;
    for (i = 0; i < L->nbelem; i++)
    {   suivant = courant->next;
/* appeler ici un �ventuel destructeur pour nouveau->value */
        free (courant);
        courant = suivant;
    }
}

void print_liste_int (struct liste_int* L)
{   struct maillon_int* M;
    int i;
    printf ("[");
    M = L->tete;
    for (i = 0; i < L->nbelem; i++)
    {   if (i == 0)
            printf ("%d", M->value);
        else
            printf (", %d", M->value);
        M = M->next;
    }
    printf ("]\n");
}

void extraire_en_tete_liste_int (struct liste_int* L, int* x){
	if (!est_vide_liste_int(L)){
		struct maillon_int* suivant;
		*x = L->tete->value;
		L->nbelem=(L->nbelem) - 1;
		suivant = L->tete->next;
		free(L->tete);
		L->tete=suivant;
	}
	else{
		printf("La file est vide!");
	}
}
