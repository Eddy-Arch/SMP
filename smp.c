#include <stdio.h>
#include <stdlib.h>
#include "config.h"
int main()
{
	char c;
	printf("-Simple MPD Player-\n");

	for (;;)
	{
		switch(c = getchar())
		{
		case '+':
			increase();
			printf("\n");
			printf(cprompt);
			break;
		case '-':
			printf("\n");
			printf(cprompt);
			decrease();
			break;
		case 'h':
			printf(cprompt);
			printf("Help Page:\n \t welcome to the help page! heres a list of the available commands: \n\t + = increases the volume. instructing more than one + increases it by the amount of + specified \n\t - = same thing as +, but decreases the volume. \n\t <spacebar> = pause/unpause the music \n\t n = next song \n\t p = previous song \n\t s <args> = searches and plays the song  \n\n\ edit keybinds: \n\t to edit the keybinds edit your config.h file.\n");
			break;
		}

		if(c == skipsong)
		{
			printf(cprompt);
			system("mpc next");
		}
		if (c == prevsong)
		{
			printf(cprompt);
			system("mpc prev");
		}
		if (c == toggle)
		{
			printf(cprompt);
			system("mpc toggle");
		}
		if (c == clearconsole)
		{
			printf("\e[1;1H\e[2J");
			printf("SMP console ~$ ");
		}
		char s[1024];
		
		if(c == search_play)
		{

		scanf("%s", s);
		printf(cprompt);
		char str[80];
		strcpy(str, "mpc searchplay ");
		strcat(str, s);
		system(str);

		}
	}
}
