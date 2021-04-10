#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>
#include <mpd/message.h>
#include "getsong.c"
#define RED "\x1b[31;01m"
#define DARKRED "\x1b[31;06m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32;06m"
#define YELLOW "\x1b[33;06m"

#include "config.h"
#include "src/func.h"

int main()
{

	bool verbose = verbose_bool;
	bool raw = raw_bool;
	bool headfull = headfull_bool;
	char c;
	char s[1024];
	printf("SMP");
	printf("\e[1;1H\e[2J");
	struct mpd_connection *conn;

	conn = mpd_connection_new(NULL, 0, 30000);

	if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS)
		return handle_error(conn);

	{
		
	}



	if(raw)
	{
		enableRawMode();
	}
                       
	for(;;){

		switch(c = getchar())
		{
		case show_cover:
			system("clear");
			system("./songchange --silent");
			system("./img.sh /tmp/kunst.jpg");
			songmain();
			break;
		case '=':
			volume_decrease;
			
		case volume_increase: 
			headfull_check(headfull);
			printf("\n");
			printf("%s", cprompt);
			increase();
			break;
		case volume_decrease:
			headfull_check(headfull);
			printf("\n");
			printf("%s", cprompt);
			decrease();
			break;
		case help_msg:
			printf("\n");
			const char* helpmsg = "\t\t\t\t\t\tHelp Page:"
				"\n\t\t\t\n\n \t\twelcome to the help page! "
				"heres a list of the available commands\n\n"
				"\n\t + = increases the volume. instructing "
				"more than one + increases it by the amount "
				"of + specified" 
				"\n\t - = same thing as +, but decreases the"
				"volume." 
				"\n\t <spacebar> = pause/unpause the music" 
				"\n\t n = next song \n\t p = previous song" 
				"\n\t <args> = searches and plays the song" 
				"\n\t CTRL+L also clears the chat." 
				"\n\t t = list the song thats being played" 
				"\n\t f to fast forward, b to fast backward" 
				"\n\t v/V = enable/disable verbosity" 
				"\n\t l = list all songs" 
				"\n\t z = play based on position" 
				"\n\t d = list all songs in the current "
				"playlist" 
				"\n\n\t edit keybinds: \n\t to edit the "
				"keybinds edit your config.h file.\n";

			printf("%s", helpmsg);
			break;
		case 'q':
			exit(1);
		case 'Q':
			exit(1);
		case 'i':
			printf("\n");
			const char* infomsg = "Author: Eddy"
						"\nversion:";
			const char* infomsg2 = "\nrepo: "
				"https://github.com/eddy-arch/smp";
			printf("\e[1;1H\e[2J%s %s %s", infomsg, 
					version, infomsg2);
			printf("%s", cprompt);
			break;
		case search_play:
			headfull_check(headfull);
			if (raw == true)
			{
				disableRawMode();
				printf("search: ");
			}


			scanf("%1024[0-9a-zA-Z ]", s);
			printf("%s", cprompt);
			char str[sizeof(s)];
			strcpy(str, "mpc -q searchplay \"");
			strcat(str, s);
			strcat(str, "\"");
			system(str);
			if (raw == true){
					enableRawMode();
				}
				break;
			break;

		case change_position:
			headfull_check(headfull);
			if (raw == true)
			{
				disableRawMode();
				printf("go to: ");
			}
			scanf("%1024[0-9a-zA-Z:]", s);
			printf("%s", cprompt);
			char str2[sizeof(s)];
			strcpy(str2, "mpc seek ");
			strcat(str2, s);
			strcat(str2, " |grep -m2 -F '#' |cut -d ' ' -f4-");
			system(str2);
			if (raw == true){
					enableRawMode();
				}
			break;

		case nowplaying:
			headfull_check(headfull);
			system("mpc -f %file%");
			printf("%s", cprompt);
			break;

		case clearconsole:
			headfull_check(headfull);
			printf("\e[1;1H\e[2J");
			printf("%s", cprompt);
			break;


		case list_title:
			headfull_check(headfull);
			system("mpc list Title");
			printf("%s", cprompt);
			break;

		case fastforward:
			headfull_check(headfull);
			fastitforward();
			printf("%s", cprompt);
			break;

		case fastbackward:
			headfull_check(headfull);
			fastitbackward();
			printf("%s", cprompt);
			break;

		case enable_headfull:
			if (headfull == false){
			headfull_check(headfull);
			headfull= true;
			printf("headfull = on\n");
			printf("%s", cprompt);

			}else if (headfull == true)
			{
				headfull_check(headfull);
				headfull = false;
				printf("headfull = off\n");
				printf("%s", cprompt);
			}
			break;

		case enable_verbose:
			if(verbose == false)
			{
				headfull_check(headfull);
				verbose = true;
				printf("verbose = on\n");
				printf("%s", cprompt);

			}else if (verbose == true)
			{
				headfull_check(headfull);
				verbose = false;
				printf("verbose = off\n");
				printf("%s", cprompt);
			}
			break;

		case enable_raw:
			if(raw == false)
			{
				headfull_check(headfull);
				raw = true;
				//tty_raw_mode();	
				enableRawMode();
				printf("raw mode on");
				printf("%s", cprompt);

			}else if (raw == true){
			
				headfull_check(headfull);
				raw = false;
				disableRawMode();
				printf("raw mode off");
				printf("%s", cprompt);
			}
			break;


		case skipsong:
			if(verbose == false)
			{
				headfull_check(headfull);
				printf("%s" , cprompt);
				system("mpc -q next");
			}else{ 
				headfull_check(headfull);
				printf("%s", cprompt);
				system("mpc -q next");
				system("mpc -f %file%");
			}
			break;



		case prevsong:
			if (verbose == false)
			{
				headfull_check(headfull);
				printf("%s", cprompt);
				system("mpc -q prev");
			}else{
				headfull_check(headfull);
				printf("%s", cprompt);
				system("mpc -q prev");
				system("mpc -f %file%");
			}
			break;


		case toggle:
			if (verbose == false)
			{
				headfull_check(headfull);
				printf("%s", cprompt);
				system("mpc -q toggle");
			}else{
				headfull_check(headfull);
				printf("%s", cprompt);
				system("mpc toggle");
			}
			break;


		case cl_clear:
			headfull_check(headfull);
			printf("\e[1;1H\e[2J");
			printf("%s", cprompt);
			break;



		case play_pos:	
			if (verbose == false)
			{
				if (raw == true)
				{
					disableRawMode();
					printf("search: ");
				}
				headfull_check(headfull);
				printf("go to song pos: ");
				scanf("%s", s);
				printf("%s", cprompt);
				char str[80];
				strcpy(str, "mpc -q play ");
				strcat(str, s);
				system(str);
			if (raw == true){
					enableRawMode();
				}
				break;


			}else{ 
				if (raw == true)
				{
					disableRawMode();
					printf("search: ");
				}
				headfull_check(headfull);
				printf("go to song pos: ");
				scanf("%s", s);
				printf("%s", cprompt);
				char str[80];
				strcpy(str, "mpc play ");
				strcat(str, s);
				system(str);
			if (raw == true){
					enableRawMode();
				}
			}
			break;
		
		case list_playlist:
			headfull_check(headfull);
			printf("%s", cprompt);
			system("mpc playlist");
			break;
		}

	
	}
        return 1;
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
