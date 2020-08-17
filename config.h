#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//change increase/decrease interval
char *upinterval = "10";
char *downinterval = "10";
//change the seek interval
char *seekforwardint = "10";
char *seekbackint = "10";

//keybinds
const char skipsong = 'n';
const char prevsong = 'p';
const char toggle = ' ';
const char clearconsole = 'c';
const char search_play = 's';
const char nowplaying = 't';
const char fastforward = 'f';
const char fastbackward = 'b';
const char list_title = 'l';
const char play_pos = 'z';
const char list_playlist = 'd';
//change the prompt
char cprompt[1024] = "SMP console ~$ ";


char *strcat(char *dest, const char *src);
void increase()
{
	char str[80];
	strcpy(str, "mpc volume +");
	strcat(str, upinterval);
	strcat(str," |grep volume");
	system(str);

}
void decrease()
{
	char str[80];
	strcpy(str, "mpc volume -");
	strcat(str, downinterval);
	strcat(str," |grep volume");
	system(str);

}
void fastitforward()
{
	char str[80];
	strcpy(str, "mpc seek +");
	strcat(str, seekforwardint);
	strcat(str, " |grep playing");
	system(str);

}
void fastitbackward()
{
	char str[80];
	strcpy(str, "mpc seek -");
	strcat(str, seekbackint);
	strcat(str, " |grep playing");
	system(str);

}

