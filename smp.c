#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "config.h"
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "func.h"
int main()
{
	bool verbose = false;
	bool raw = false;
	bool headfull = false;
	char c;
	printf("\e[1;1H\e[2J");
	printf("-Simple MPD Player-\n");

	for (;;)
	{
		switch(c = getchar())
		{
		case '+':
			headfull_check(headfull);
			printf("\n");
			printf("%s", cprompt);
			increase();
			break;
		case '-':
			headfull_check(headfull);
			printf("\n");
			printf("%s", cprompt);
			decrease();
			break;
		case 'h':
			printf("%s", cprompt);
			printf("Help Page:\n \t welcome to the help page! heres a list of the available commands: \n\t + = increases the volume. instructing more than one + increases it by the amount of + specified \n\t - = same thing as +, but decreases the volume. \n\t <spacebar> = pause/unpause the music \n\t n = next song \n\t p = previous song \n\t s <args> = searches and plays the song \n\t CTRL+L also clears the chat. \n\t t = list the song thats being played\n\t f to fast forward, b to fast backward \n\t v/V = enable/disable verbosity \n\t l = list all songs \n\t z = play based on position \n\t d = list all songs in the current playlist \n\n edit keybinds: \n\t to edit the keybinds edit your config.h file.\n");
			break;
		case 'q':
			exit(1);
		case 'Q':
			exit(1);
		}

		if(c == enable_headfull && headfull == false)
		{
			headfull_check(headfull);
			headfull= true;
			printf("headfull = on\n");
			printf("%s", cprompt);

		}else if (c == enable_headfull && headfull == true)
		{
			headfull_check(headfull);
			headfull = false;
			printf("headfull = off\n");
			printf("%s", cprompt);
		}
		//
		//
		//
		//

		if(c == enable_verbose && verbose == false)
		{
			headfull_check(headfull);
			verbose = true;
			printf("verbose = on\n");
			printf("%s", cprompt);

		}else if (c == enable_verbose && verbose == true)
		{
			headfull_check(headfull);
			verbose = false;
			printf("verbose = off\n");
			printf("%s", cprompt);
		}
		//
		//
		//
		//
		//
		if(c == enable_raw && raw == false)
		{
			headfull_check(headfull);
			raw = true;
			//tty_raw_mode();	
			enableRawMode();
			printf("raw mode on");
			printf("%s", cprompt);

		}else if (c == enable_raw && raw == true)
		{
			headfull_check(headfull);
			raw = false;
			disableRawMode();
			printf("raw mode off");
			printf("%s", cprompt);
		}

		if(c == skipsong && verbose == false)
		{
			headfull_check(headfull);
			printf("%s" , cprompt);
			system("mpc -q next");
		}else if(c == skipsong){
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc -q next");
			system("mpc -f %file%");
		}
		if (c == prevsong && verbose == false)
		{
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc -q prev");
		}else if(c == prevsong){
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc -q prev");
			system("mpc -f %file%");
		}
		if (c == toggle && verbose == false)
		{
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc -q toggle");
		}else if(c == toggle){
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc toggle");
		}
		if (c == clearconsole)
		{
			headfull_check(headfull);
			printf("\e[1;1H\e[2J");
			printf("%s", cprompt);
		}
		char s[1024];
		
		if(c == search_play)
		{
		headfull_check(headfull);
		scanf("%1024s", s);
		printf("%s", cprompt);
		char str[80];
		strcpy(str, "mpc -q searchplay ");
		strcat(str, s);
		system(str);

		}
		if( c == 0x0C )
		{
			headfull_check(headfull);
			printf("\e[1;1H\e[2J");
			printf("%s", cprompt);
		}
		if (c == nowplaying)
		{
			headfull_check(headfull);
			system("mpc -f %file%");
			printf("%s", cprompt);
		}
		if (c == fastforward)
		{
			headfull_check(headfull);
			fastitforward();
			printf("%s", cprompt);
		}
		if (c == fastbackward)
		{
			headfull_check(headfull);
			fastitbackward();
			printf("%s", cprompt);
		}
		if (c == list_title)
		{
			headfull_check(headfull);
			system("mpc list Title");
			printf("%s", cprompt);
		}
		if (c == play_pos && verbose == false)
		{
		headfull_check(headfull);
		scanf("%s", s);
		printf("%s", cprompt);
		char str[80];
		strcpy(str, "mpc -q play ");
		strcat(str, s);
		system(str);


		}else if(c == play_pos){
			headfull_check(headfull);
			scanf("%s", s);
			printf("%s", cprompt);
			char str[80];
			strcpy(str, "mpc play ");
			strcat(str, s);
			system(str);
		}

		if (c == list_playlist)
		{
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc playlist");
		}
	}
}
struct termios orig_termios;
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
void tty_raw_mode(void)
{
	struct termios tty_attr;
     
	tcgetattr(0,&tty_attr);

	/* Set raw mode. */
	tty_attr.c_lflag &= (~(ICANON|ECHO));
	tty_attr.c_cc[VTIME] = 0;
	tty_attr.c_cc[VMIN] = 1;
     
	tcsetattr(0,TCSANOW,&tty_attr);
}
