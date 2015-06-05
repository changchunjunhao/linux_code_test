#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE (128)
int main()
{
	char *my_ptr = (char*)malloc(BLOCK_SIZE);
	if (!my_ptr)
	{
		printf("error malloc my_ptr");
		exit (1);
	}		
	sprintf(my_ptr, "hellow world");

	//	ex2
	free (my_ptr);
	sprintf(my_ptr, "new world");
	printf("%s\n", my_ptr);

	/*
	char *tmp_ptr = my_ptr;
	tmp_ptr = realloc(tmp_ptr, BLOCK_SIZE*2);
	
	if (tmp_ptr != NULL) {
		printf("tmp_ptr is not null\n");
		sprintf(tmp_ptr, "new hello world");
		free(my_ptr);
		sprintf(my_ptr, "can I hello world");
		printf("my_ptr: %s\n", my_ptr);
		printf("tmp_ptr: %s\n", tmp_ptr);
		my_ptr = tmp_ptr;
		printf("my_ptr: %s\n", my_ptr);
	}
	*/
	exit(0);
}
