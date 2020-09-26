![Alt text](src/smp.png?raw=true "Simple Music Player")
# Simple MPD player
## a Simple MPD player written in C

### features:
- customizable keybinds (via config.h)
- minimalistic
- easy to understand (the code is simple)
- has all the basic features (pause/unpause skip, play previous song, vol up/down)
- no ncurses (free of gnu/bloat)

## contributing
### feel free to contribute and modify this as you wish.

## installation
### using the makefile 
#### to install the program, the folllowing commands must be run
```  sudo make clean install```
#### this will execute the instructions in the makefile, that are needed to properly install SMP
## dependencies
- mpc
- mpd

## documentation
[docs](KEYBINDS.md)
