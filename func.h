#include <stdio.h>
void enableRawMode();
void tty_raw_mode(void);
void disableRawMode(); 

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

