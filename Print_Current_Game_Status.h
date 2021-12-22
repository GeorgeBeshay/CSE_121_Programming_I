/*
Module Description:
Containing 2 Functions in colours
One To Print The Between turns Game Status
The other is to print the final result of who won the game
Both take one Argument:
Current_Game predifined as a Game_Info Structure
*/

#ifndef PRINT_CURRENT_GAME_STATUS_H
#define PRINT_CURRENT_GAME_STATUS_H

# include "Colours.h"

void Print_Current_Game_Status(struct Game_Info Current_Game)
{
    printf(
            CYAN "                  Borders     Boxes\n"
        RED  "Player A:         %d           %d\n"
        BLUE "Player B:         %d           %d\n"
        CYAN "Game Remaining:   %d           %d\n"
	"---------------------------------------------\n"
	RESET
        ,Current_Game.First_Player_Borders
        ,Current_Game.First_Player_Boxes
        ,Current_Game.Second_Player_Borders
        ,Current_Game.Second_Player_Boxes
        ,Current_Game.Remaining_Borders
        ,Current_Game.Remaining_Boxes
        );
}

void Print_Who_Won(struct Game_Info Current_Game)
{
    if(Current_Game.First_Player_Boxes > Current_Game.Second_Player_Boxes)
    {
        printf(RED "Player A Has Won The Game\nCongratulations !!\n");
    }
    else if(Current_Game.First_Player_Boxes < Current_Game.Second_Player_Boxes)
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