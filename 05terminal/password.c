#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN 8

int main()
{
	struct termios initialrsettings, newrsettings;
	char password[PASSWORD_LEN + 1];
	//0
	//printf("fileno(stdin) is %d\n", fileno(stdin));
	//printf("sizeof(tcflag_t) is %ld\n", sizeof(tcflag_t));
	//printf("sizeof(cc_t) is %ld\n", sizeof(cc_t));
	//printf("sizeof(termios) is %ld\n", sizeof(newrsettings));
	tcgetattr(fileno(stdin), &initialrsettings);
	
	newrsettings = initialrsettings;
	//printf("c_lflag is %X\n", newrsettings.c_lflag);
	//printf("ECHO is %x\n", ECHO);
	
	// 输入密码时，关闭回显
	newrsettings.c_lflag &= ~ECHO;
	
	// 尝试输入超时，输入字符控制
	newrsettings.c_lflag &= ~ICANON;
	newrsettings.c_lflag &= ~ISIG;
	newrsettings.c_cc[VTIME] = 0;
	newrsettings.c_cc[VMIN] = 1;


	printf ("Enter password: ");

	if (tcsetattr(fileno(stdin), TCSANOW, &newrsettings) != 0) {
		fprintf(stderr, "Could not set attributes\n");
	} else {
		fgets(password, PASSWORD_LEN, stdin);
		tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
		fprintf(stdout, "\nYou entered %s\n", password);
	}
	
	/**
	printf("c_oflag is %x\n", newrsettings.c_oflag);
	printf("OPOST is %x\n", OPOST);
	printf("ONLRET is %x\n", ONLRET);
	//exit(0);
	//newrsettings.c_oflag |= ~OPOST;	
	newrsettings.c_oflag |= OLCUC;
	tcsetattr(fileno(stdin), TCSANOW, &newrsettings);

	int index = 100;
	while (index --)
		printf("hello world\n");

	tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
	**/
	exit(0);
}
