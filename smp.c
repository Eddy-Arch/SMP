#include <stdio.h>
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
			break;
		case '-':
			decrease();
			break;
		case 'h':
			printf("Help Page:\n \t welcome to the help page! heres a list of the available commands: \n\t + = increases the volume. instructing more than one + increases it by the amount of + specified \n\t - = same thing as +, but decreases the volume. \n\t <spacebar> = pause/unpause the music \n\t n = next song \n\t p = previous song \n\n\ edit keybinds: \n\t to edit the keybinds edit your config.h file.\n");
			break;
		}

		if(c == skipsong)
		{
			system("mpc next");
		}
		if (c == prevsong)
		{
			system("mpc prev");
		}
		if (c == toggle)
		{
			system("mpc toggle");
		}
		if (c == clearconsole)
		{
			printf("\e[1;1H\e[2J");
		}
	}
}
