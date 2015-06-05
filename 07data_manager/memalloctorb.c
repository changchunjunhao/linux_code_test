#include <stdlib.h>

int main()
{
	char *some_memory;

	int destination = 0;
	printf("cin the memory destination:");
	scanf("%x", &destination);
	printf("destination is %x\n", destination);
	some_memory = (char*)destination;

	printf("some_memory:\n%s\n", some_memory);

	return 0;
}
