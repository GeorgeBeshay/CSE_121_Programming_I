/*
Module Description:
Function To Print The Current Board View IN COLOURS, Will the chosen / remaining borders & boxes.
Taking 4 Arguments: (x,y,Beginner_Board[x][y],Beginner_Board_Colour[x][y])
*/

#ifndef PRINT_CURRENT_BOARD_H
#define PRINT_CURRENT_BOARD_H

#include "Colours.h"

void Print_Current_Board(int x,int y,int Beginner_Board[x][y],int Beginner_Board_Colour[x][y])
{
for(int i=0 ; i<6 ; i++)
    {
        for(int j=0 ; j<6 ; j++)
        {
            if(i==0 && j==0)
            {
                printf(CYAN "%c " RESET,Beginner_Board[i][j]);
            }
            else if(i==0 || j==0)
            {
                printf(CYAN "%d " RESET,Beginner_Board[i][j]);
            }
            else if(i%2!=0 && j%2!=0)
            {
                printf(CYAN "%c " RESET,Beginner_Board[i][j]);
            }
            else
            {   if(Beginner_Board_Colour[i][j]==1)
                {
                    printf(RED);
                }
                else
                {
                    printf(BLUE);
                }
                printf("%c " RESET,Beginner_Board[i][j]);
            }
        }
        printf("\n");
    }
}

#endif