/**********************************************************************
 * IMPLANTATION
 *
 * Spécification de l'implantation
 *
 * Implantation des listes simplement chaînées de int
 *
 * Les maillons sont alloués dynamiquement.
 * Le champ next du dernier maillon vaut (struct maillon_int*)0
 *
 * Le champ tete d'une liste pointe vers le premier maillon
 * Le champ queue d'une liste pointe vers le dernier maillon
 * Le champ nbelem est égal au nombre de maillons de la liste
 * La liste vide est codée par (tete, nbelem) = ((struct maillon_int*)0, 0)
 *
 * Des listes distinctes ont des maillons distincts (pas de maillon partagé).
 **********************************************************************/

struct maillon_int
{   int value;
    struct maillon_int* next;
    struct maillon_int* before;
};

struct liste_int
{   struct maillon_int* tete;
    struct maillon_int* queue;
    int nbelem;
};

#define NIL (struct maillon_int*)0

/**********************************************************************
 * PROTOTYPES DES FONCTIONS (TYPE ABSTRAIT)
 **********************************************************************/
extern int est_vide_liste_int(struct liste_int*);
/*
 * Constructeur. Initialise son paramètre à la liste vide
 */

extern void init_liste_int (struct liste_int*);

/*
 * Destructeur
 */

extern void clear_liste_int (struct liste_int*);

/* Affiche son paramètre sur la sortie standard. */
extern void print_liste_int (struct liste_int);

/* extrait d en tête de la liste L. La liste L est modifiée. */
extern void extraire_en_tete_liste_int (struct liste_int* L, int x);

/* Ajoute d en queue de la liste L. La liste L est modifiée. */
extern void ajout_en_queue_liste_int (struct liste_int* L, int x);
