/*
Module Description:
Defining Colours ASCII Codes
*/

#ifndef COLOURS_H
#define COLOURS_H

#include <stdio.h>
// foreground color 
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define WHITE   "\x1b[37m"

// background color
#define RRED     "\x1b[41m"
#define GGREEN   "\x1b[42m"
#define YYELLOW  "\x1b[43m"
#define BBLUE    "\x1b[44m"
#define MMAGENTA "\x1b[45m"
#define CCYAN    "\x1b[46m"
#define RRESET   "\x1b[0m"
#define WWHITE   "\x1b[47m"

#endif