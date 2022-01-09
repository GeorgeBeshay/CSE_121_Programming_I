/*
Module Description:
Function that initializes the beginner board view.
Taking 3 Arguments (x,y,BeginnerBoard[x][y])
*/

#ifndef INITIALIZE_PVP_BEGINNER_BOARD_H
#define INITIALIZE_PVP_BEGINNER_BOARD_H

void Initialize_PvP_Beginner_Board(int x,int y,int Beginner_Board[x][y])
{
    for(int i=0 ; i<6 ; i++)
    {
        for(int j=0 ; j<6 ; j++)
        {
            if(i==0 && j==0)
            {
                Beginner_Board[i][j]=' '; // First element TOP LEFT is Empty(Space) 
            }
            else if(i==0 || j==0)
            {
                if(i == 0)
                {
                    Beginner_Board[i][j]=j; // If Any Element in first row should show the column number which is j
                }
                if(j == 0)
                {
                    Beginner_Board[i][j]=i; // If Any Element in first Column should show the row number which is i
                }
            }
            else if(i%2!=0 && j%2!=0)
            {
                Beginner_Board[i][j]=254; // White block(dot)
            }
            else
            {
                Beginner_Board[i][j]=' '; // Initializing these places Empty, will be filled with dashes
            }
        }
    }
}

#endif