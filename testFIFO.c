#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "file_int.h"

int main ()
{
  struct file_int F;
  init_file_int (&F);
  enfiler_int(&F,7);
  enfiler_int(&F,77);
  imprimer_file_int(&F);
  int v;
  defiler_int(&v,&F);
  imprimer_file_int(&F);
  return 0;
}
