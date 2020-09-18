#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//change increase/decrease interval
char *upinterval = "10";
char *downinterval = "10";
//change the seek interval
char *seekforwardint = "10";
char *seekbackint = "10";

//keybinds//
const char skipsong = 'n';
const char prevsong = 'p';
const char toggle = 0x10;
const char clearconsole = 'c';
const char search_play = 's';
const char nowplaying = 't';
const char fastforward = 'f';
const char fastbackward = 'b';
const char list_title = 'l';
const char play_pos = 'z';
const char list_playlist = 'd';
const char enable_raw = 'r';
const char enable_verbose = 'v';
const char enable_headfull = 'H';
//change the prompt
char cprompt[] = "\nSMP console ~$ ";
//modes
//should headfull be enabled by default?
bool headfull_bool = true;
//should raw be enabled by default?
bool raw_bool = true;
// should verbose be enabled by default?
bool verbose_bool = true;

