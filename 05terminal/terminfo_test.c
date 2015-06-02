#include <term.h>
#include <stdio.h>

int main()
{
	setupterm(NULL, 1, (int*)0);
	printf("begin");

	char *cursor;
	char *esc_sequence;
	cursor = tigetstr("cup");
	esc_sequence = tparm(cursor, 5, 30);
	tputs(esc_sequence, 1, NULL);

	printf("done");
}
