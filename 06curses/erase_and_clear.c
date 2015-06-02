#include <curses.h>

//clear or erase will clear the screen and this job canot undo


int main()
{
	initscr();

	printw("hello world");
	refresh();
	beep();

	sleep(2);

	clear();
	refresh();
	beep();

	sleep(2);

	erase();
	refresh();
	beep();

	sleep(2);

	endwin();
}
