#include "file_int.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct file_int F;

	init_file_int(&F);

	enfiler_int(&F,7);
	enfiler_int(&F,77);

	imprimer_file_int(&F);

	clear_file_int(&F);
	return 0;
}
