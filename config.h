//volume increase intervals
#include <string.h>
#include <stdio.h>
//change increase/decrease interval
char *upinterval = "10";
char *downinterval = "10";
//keybinds
const char skipsong = 'n';
const char prevsong = 'p';
const char toggle = ' ';
const char clearconsole = 'c';

char *strcat(char *dest, const char *src);
void increase()
{
	char str[80];
	strcpy(str, "mpc volume +");
	strcat(str, upinterval);
	system(str);

}
void decrease()
{
	char str[80];
	strcpy(str, "mpc volume -");
	strcat(str, downinterval);
	system(str);

}

