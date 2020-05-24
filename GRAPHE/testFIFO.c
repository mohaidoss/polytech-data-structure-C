#include "file_int.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct file_int F;

	init_file_int(&F);

	enfiler_int(&F,7);
	imprimer_file_int(&F);
	enfiler_int(&F,77);

	imprimer_file_int(&F);
	enfiler_int(&F,42);
	enfiler_int(&F,6);
	imprimer_file_int(&F);


	int a;
	defiler_int(&a,&F);
	printf("%d\n",a);
	enfiler_int(&F,10);
	int b;
	defiler_int(&b,&F);
	printf("%d\n",b);
	imprimer_file_int(&F);

	clear_file_int(&F);
	return 0;
}
