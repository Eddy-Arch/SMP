#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "config.h"
int main()
{
	bool verbose = false;
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
			printf("Help Page:\n \t welcome to the help page! heres a list of the available commands: \n\t + = increases the volume. instructing more than one + increases it by the amount of + specified \n\t - = same thing as +, but decreases the volume. \n\t <spacebar> = pause/unpause the music \n\t n = next song \n\t p = previous song \n\t s <args> = searches and plays the song \n\t CTRL+L also clears the chat. \n\t t = list the song thats being played\n\t f to fast forward, b to fast backward \n\t v/V = enable/disable verbosity \n\t l = list all songs \n\n edit keybinds: \n\t to edit the keybinds edit your config.h file.\n");
			break;
		case 'v':
			verbose = true;
			printf("verbose = on\n");
			printf(cprompt);
			break;
		case 'V':
			verbose = false;
			printf("verbose = off\n");
			printf(cprompt);
			break;
		case 'q':
			exit(1);
		case 'Q':
			exit(1);
		}

		if(c == skipsong && verbose == false)
		{
			printf(cprompt);
			system("mpc -q next");
		}else if(c == skipsong){
			printf(cprompt);
			system("mpc next");
		}
		if (c == prevsong && verbose == false)
		{
			printf(cprompt);
			system("mpc -q prev");
		}else if(c == prevsong){
			printf(cprompt);
			system("mpc next");
		}
		if (c == toggle && verbose == false)
		{
			printf(cprompt);
			system("mpc -q toggle");
		}else if(c == toggle){
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
		strcpy(str, "mpc -q searchplay ");
		strcat(str, s);
		system(str);

		}
		if( c == 0x0C )
		{
			printf("\e[1;1H\e[2J");
			printf(cprompt);
		}
		if (c == nowplaying)
		{
			system("mpc -f %file%");
			printf(cprompt);
		}
		if (c == fastforward)
		{
			fastitforward();
			printf(cprompt);
		}
		if (c == fastbackward)
		{
			fastitbackward();
			printf(cprompt);
		}
		if (c == list_title)
		{
			system("mpc list Title");
			printf(cprompt);
		}
	}
}
