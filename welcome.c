#include <stdio.h>
#include "config.h"

main()
{
	char c;
	char *strcat(char *dest, const char *src);
	char str[80];

		
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
	}
}
