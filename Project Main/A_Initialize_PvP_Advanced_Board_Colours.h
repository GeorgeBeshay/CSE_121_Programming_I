/*
Module Description:
Each Element in the Colour Array will have a value which identifies whether Player A
or Player B has placed the border.
Also it will print the Boxes, Numbering Digits in CYAN Colour.
0  -> Box,Rows & Columns Numbering, and TOP LEFT ELEMENT (Empty) : CYAN 
1  -> Dash By Player A                                           : RED
-1 -> Dash By Player B                                           : BLUE
*/

#ifndef A_INITIALIZE_PVP_ADVANCED_COLOURS_H
#define A_INITIALIZE_PVP_ADVANCED_COLOURS_H

void Intialize_PvP_Advanced_Board_Colour(int x,int y,int Advanced_Board_Colour[x][y])
{
    for(int i=0 ; i<12 ; i++)
    {
        for(int j=0 ; j<12 ; j++)
        {
            if(i==0 && j==0)
            {
                Advanced_Board_Colour[i][j]=0; // First element TOP LEFT is Empty(Space) 
            }
            else if(i==0 || j==0)
            {
                if(i == 0)
                {
                    Advanced_Board_Colour[i][j]=0; // If Any Element in first row should show the column number which is j
                }
                if(j == 0)
                {
                    Advanced_Board_Colour[i][j]=0; // If Any Element in first Column should show the row number which is i
                }
            }
            else if(i%2!=0 && j%2!=0)
            {
                Advanced_Board_Colour[i][j]=0; // White block(dot)
            }
            else
            {
                Advanced_Board_Colour[i][j]=0; // Initializing these places Empty, will be filled with dashes
            }
        }
    }
}

#endif