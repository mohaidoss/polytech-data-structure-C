#include "liste_int.h"

struct file_int
{
    struct liste_int *L;
};

void init_file_int (struct file_int*);
int est_vide_file_int (struct file_int*);
void enfiler_int (struct file_int*, int);
void defiler_int (int *, struct file_int*);
void imprimer_file_int(struct file_int*);
void clear_file_int(struct file_int*);
