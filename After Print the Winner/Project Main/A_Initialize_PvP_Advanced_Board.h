/*
Module Description:
Function that initializes the Advanced board view.
Taking 3 Arguments (x,y,AdvancedBoard[x][y])
*/

#ifndef A_INITIALIZE_PVP_ADVANCED_BOARD_H
#define A_INITIALIZE_PVP_ADVANCED_BOARD_H
void A_Initialize_PvP_Advamced_Board(int x,int y,int Advanced_Board[x][y])
{
    for(int i=0 ; i<12 ; i++)
    {
        for(int j=0 ; j<12 ; j++)
        {
            if(i==0 && j==0)
            {
                Advanced_Board[i][j]=' '; // First element TOP LEFT is Empty(Space) 
            }
            else if(i==0 || j==0)
            {
                if(i == 0)
                {
                    Advanced_Board[i][j]=j; // If Any Element in first row should show the column number which is j
                }
                if(j == 0)
                {
                    Advanced_Board[i][j]=i; // If Any Element in first Column should show the row number which is i
                }
            }
            else if(i%2!=0 && j%2!=0)
            {
                Advanced_Board[i][j]=254; // White block(dot)
            }
            else
            {
                Advanced_Board[i][j]=' '; // Initializing these places Empty, will be filled with dashes
            }
        }
    }
}
#endif