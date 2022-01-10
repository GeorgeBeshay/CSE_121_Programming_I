/*
Module Description:
Containing 2 Functions in colours
One To Print The Between turns Game Status
The other is to print the final result of who won the game
-Function Print_Current_Game_Status take one Argument:
A_Current_Game predifined as a A_Game_Info Structure
-Function Print_Who_Won take 3 Arguments:
A_Current_Game predifined as a Game_Info Structure, Player_A_Name , Player_B_Name.
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

void A_Print_Who_Won(struct A_Game_Info A_Current_Game,char A_Player_A_Name[100],char A_Player_B_Name[100])
{
    if(A_Current_Game.A_First_Player_Boxes > A_Current_Game.A_Second_Player_Boxes)
    {
        printf(RED "%s Has Won The Game\nCongratulations !!\n",A_Player_A_Name);
    }
    else if(A_Current_Game.A_First_Player_Boxes < A_Current_Game.A_Second_Player_Boxes)
    {
        printf(BLUE "%s Has Won The Game\nCongratulations !!\n",A_Player_B_Name);
    }
    else
    {
        printf(CYAN "DRAW\nThere is no Winner !!\n");
    }
	printf(RESET);
}

#endif