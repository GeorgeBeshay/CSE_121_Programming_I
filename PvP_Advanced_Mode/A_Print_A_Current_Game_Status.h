/*
Module Description:
Containing 2 Functions in colours
One To Print The Between turns Game Status
The other is to print the final result of who won the game
Both take one Argument:
A_Current_Game predifined as a A_Game_Info Structure
*/

#ifndef A_PRINT_A_Current_Game_STATUS_H
#define A_PRINT_A_Current_Game_STATUS_H

#include "Colours.h"

void A_Print_A_Current_Game_Status(struct A_Game_Info A_Current_Game)
{
    printf(
            CYAN "                  Borders     Boxes\n"
        RED  "Player A:         %d           %d\n"
        BLUE "Player B:         %d           %d\n"
        CYAN "Game Remaining:   %d           %d\n"
	"---------------------------------------------\n"
	RESET
        ,A_Current_Game.A_First_Player_Borders
        ,A_Current_Game.A_First_Player_Boxes
        ,A_Current_Game.A_Second_Player_Borders
        ,A_Current_Game.A_Second_Player_Boxes
        ,A_Current_Game.A_Remaining_Borders
        ,A_Current_Game.A_Remaining_Boxes
        );
}

void Print_Who_Won(struct A_Game_Info A_Current_Game)
{
    if(A_Current_Game.A_First_Player_Boxes > A_Current_Game.A_Second_Player_Boxes)
    {
        printf(RED "Player A Has Won The Game\nCongratulations !!\n");
    }
    else if(A_Current_Game.A_First_Player_Boxes < A_Current_Game.A_Second_Player_Boxes)
    {
        printf(BLUE "Player B Has Won The Game\nCongratulations !!\n");
    }
    else
    {
        printf(CYAN "DRAW\nThere is no Winner !!\n");
    }
	printf(RESET);
}

#endif