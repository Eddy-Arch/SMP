#!/bin/bash
test -z "$1" && exit

W3MIMGDISPLAY="/usr/lib/w3m/w3mimgdisplay"
FILENAME=$1
FONTH=14 # Size of one terminal row
FONTW=1  # Size of one terminal column
#14 8
COLUMNS=`tput cols`
LINES=`tput lines`

read width height <<< `echo -e "5;$FILENAME" | $W3MIMGDISPLAY`

max_width=$(($FONTW * $COLUMNS))
max_height=$(($FONTH * $(($LINES - 2)))) # substract one line for prompt

if test $width -gt $max_width; then
height=$(($height * $max_width / $width))
width=$max_width
fi
if test $height -gt $max_height; then
width=$(($width * $max_height / $height))
height=$max_height
fi

w3m_command="0;1;1;1;125;125;;;;;$FILENAME\n4;\n3;"

tput cup $(($height/$FONTH)) 0
echo -e $w3m_command|$W3MIMGDISPLAY
