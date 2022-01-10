/*
Module Description:
Function Taking 6 Arguments (x,y,Advanced_Board[x][y],Player who has played,Temp array of status,Advanced_Board_Colour[x][y]) containing whether
the player had created a box or not, if yes RE_Play will occur.
*/

#ifndef A_CHECK_FOR_BOXES_AND_RE_PLAY_H
#define A_CHECK_FOR_BOXES_AND_RE_PLAY_H

void A_Check_For_Boxes_and_RE_Play(int x,int y,int Advanced_Board[][y],char player,int temp[2],int Advanced_Board_Colour[x][y])
{
    int RE_Play=0;
    int Boxes_Created=0;
    for(int i=0 ; i<25 ; i++) // 25 boxes to check, then 25 loops
    {
        for(int j=2 ; j<11 ; j=j+2) // j = [2,4,6,8,10]
        {
            for(int k=2 ; k<11 ; k=k+2) // k = [2,4,6,8,10]
            {
                if(Advanced_Board[j][k]==' ') // Checking if the center of the box is empty or not
                {
                    int counter=0; // Borders counter 
                    if(Advanced_Board[j-1][k]!=' '){counter++;} // Checking each border surrounding the center of the box
                    if(Advanced_Board[j+1][k]!=' '){counter++;}
                    if(Advanced_Board[j][k-1]!=' '){counter++;}
                    if(Advanced_Board[j][k+1]!=' '){counter++;}
                    if(counter == 4) // if 4 borders are counted
                    {
                        Advanced_Board[j][k]=player; // Then place the letter of the player in the center of the box
                        if (player=='A')
                        {
                        Advanced_Board_Colour[j][k]=1;
                        }
                        else
                        {
                        Advanced_Board_Colour[j][k]=-1;
                        }
                        temp[1]=1; // Box created, then RE_Play
                        temp[0]++; // Box created, add it
                    }
                }
            }
        } 
    }
}

#endif