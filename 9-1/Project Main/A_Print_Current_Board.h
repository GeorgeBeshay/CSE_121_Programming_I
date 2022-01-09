/*
Module Description:
Function To Print The Current Board View IN COLOURS, Will the chosen / remaining borders & boxes.
Taking 4 Arguments: (x,y,Advanced_Board[x][y],Advanced_Board_Colour[x][y])
*/

#ifndef A_PRINT_CURRENT_BOARD_H
#define A_PRINT_CURRENT_BOARD_H

#include "Colours.h"

void A_Print_Current_Board(int x,int y,int Advanced_Board[][y],int Advanced_Board_Colour[x][y])
{
for(int i=0 ; i<12 ; i++)
    {
        for(int j=0 ; j<12 ; j++)
        {
            if(i==0 && j==0)
            {
                printf(CYAN "%c " RESET,Advanced_Board[i][j]);
            }
            else if(i==0 || j==0)
            {  
                if(i<10 && j<10)
                {
                    printf(CYAN "0%d " RESET,Advanced_Board[i][j]);
                }
                else
                {
                    printf(CYAN "%d " RESET,Advanced_Board[i][j]);
                }
            }
            else if(i%2!=0 && j%2!=0)
            {
                printf(CYAN "%c   " RESET,Advanced_Board[i][j]);
            }
            else if(i%2!=0 && j%2==0)
            {
		if(Advanced_Board_Colour[i][j]==1)
		{
			printf(RED);
		}
		else
		{
			printf(BLUE);
		}
                printf("\b\b%c%c%c " RESET,Advanced_Board[i][j],Advanced_Board[i][j],Advanced_Board[i][j]);
            }
            else
            {
		if(Advanced_Board_Colour[i][j]==1)
		{
			printf(RED);
		}
		else
		{
			printf(BLUE);
		}
                printf("%c  " RESET,Advanced_Board[i][j]);
            }
        }
        printf("\n");
    }
}

#endif