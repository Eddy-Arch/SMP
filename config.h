//change increase/decrease interval
char *upinterval = "10";
char *downinterval = "10";
//change the seek interval
char *seekforwardint = "10";
char *seekbackint = "10";

//keybinds//
#define skipsong 'n'
#define prevsong 'p'
#define toggle ' ' //0x10 for ctrl + p
#define clearconsole 'c'
#define search_play 's'
#define nowplaying 't'
#define fastforward 'f'
#define fastbackward 'b'
#define list_title 'l'
#define play_pos 'z'
#define list_playlist 'd'
#define enable_raw 'r'
#define enable_verbose 'v'
#define enable_headfull 'H'
#define help_msg 'h'
#define volume_increase '+'
#define volume_decrease '-'
#define change_position 'g'
//change the prompt
char cprompt[] = "\n";
//modes
//should headfull be enabled by default?
bool headfull_bool = true;
//should raw be enabled by default?
bool raw_bool = true;
// should verbose be enabled by default?
bool verbose_bool = false;
// should album previews be enabled by default
bool showalbum = true;

//clear the text with ctrl + l
#define cl_clear 0x0C
 
