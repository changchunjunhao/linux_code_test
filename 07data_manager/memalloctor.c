#include <stdlib.h>
#include <stdio.h>

#define MALLOC_SIZE (128)
#define SLEEP_TIME (60*60)
int main()
{
	char *some_memory;
	int i = 0;

	some_memory = (char*)malloc(MALLOC_SIZE);
	if (some_memory != NULL) {
		printf("first time:\n");
		for (i = 0; i < MALLOC_SIZE; i++)
			printf("%d:%c\n", i, some_memory[i]);
		sprintf(some_memory, "hello world from partner a");
		printf("first time:\n");
		for (i = 0; i < MALLOC_SIZE; i++)
			printf("%d:%c\n", i, some_memory[i]);
	//	int addr = (int)(some_memory);
		printf("some_memory is in here %x\n",some_memory);
		sleep(SLEEP_TIME);
	}

	return 0;
}
