/*
Module Description:
Containing 2 Functions in colours
One To Print The Between turns Game Status
The other is to print the final result of who won the game
-Function Print_Current_Game_Status take one Argument:
Current_Game predifined as a Game_Info Structure
-Function Print_Who_Won take 3 Arguments:
Current_Game predifined as a Game_Info Structure, Player_A_Name , Player_B_Name.
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

void Print_Who_Won(struct Game_Info Current_Game, char Player_A_Name[100],char Player_B_Name[100])
{
    if(Current_Game.First_Player_Boxes > Current_Game.Second_Player_Boxes)
    {
        printf(RED "%s Has Won The Game\nCongratulations !!\n", Player_A_Name);
    }
    else if(Current_Game.First_Player_Boxes < Current_Game.Second_Player_Boxes)
    {
        printf(BLUE "%s Has Won The Game\nCongratulations !!\n", Player_B_Name);
    }
    else
    {
        printf(CYAN "DRAW\nThere is no Winner !!\n");
    }
	printf(RESET);
}

#endif