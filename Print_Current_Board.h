/*
Module Description:
Function To Print The Current Board View, Will the chosen / remaining borders & boxes.
Taking 3 Arguments: (x,y,Beginner_Board[x][y])
*/

#ifndef PRINT_CURRENT_BOARD_H
#define PRINT_CURRENT_BOARD_H

void Print_Current_Board(int x,int y,int Beginner_Board[][y])
{
for(int i=0 ; i<6 ; i++)
    {
        for(int j=0 ; j<6 ; j++)
        {
            if(i==0 && j==0)
            {
                printf("%c ",Beginner_Board[i][j]);
            }
            else if(i==0 || j==0)
            {
                printf("%d ",Beginner_Board[i][j]);
            }
            else if(i%2!=0 && j%2!=0)
            {
                printf("%c ",Beginner_Board[i][j]);
            }
            else
            {
                printf("%c ",Beginner_Board[i][j]);
            }
        }
        printf("\n");
    }
}

#endif