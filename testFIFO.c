#include "file_int.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("a\n");
	struct file_int F;
	printf("b\n");
	init_file_int(&F);
	printf("c\n");
	enfiler_int(&F,7);
	imprimer_file_int(&F);
	printf("7\n");
	enfiler_int(&F,77);
	imprimer_file_int(&F);
	int v;
	printf("sa\n");
	defiler_int(&v,&F);
	imprimer_file_int(&F);
	clear_file_int(&F);
	return 0;
}
