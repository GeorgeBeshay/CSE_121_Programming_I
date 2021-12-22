/*
Module Description:
Function Taking 6 Arguments (x,y,Beignner_Board[x][y],Player who has played,Temp array of status,Beginner_Board_Colour[x][y]) containing whether
the player had created a box or not, if yes RE_Play will occur.
*/

#ifndef CHECK_FOR_BOXES_AND_RE_PLAY_H
#define CHECK_FOR_BOXES_AND_RE_PLAY_H

void Check_For_Boxes_and_RE_Play(int x,int y,int Beginner_Board[][y],char player,int temp[2],int Beginner_Board_Colour[x][y])
{
    int RE_Play=0;
    int Boxes_Created=0;
    for(int i=0 ; i<4 ; i++) // 4 boxes to check, then 4 loops
    {
        for(int j=2 ; j<5 ; j*=2) // j = [2,4]
        {
            for(int k=2 ; k<5 ; k*=2) // k = [2,4]
            {
                if(Beginner_Board[j][k]==' ') // Checking if the center of the box is empty or not
                {
                    int counter=0; // Borders counter 
                    if(Beginner_Board[j-1][k]!=' '){counter++;} // Checking each border surrounding the center of the box
                    if(Beginner_Board[j+1][k]!=' '){counter++;}
                    if(Beginner_Board[j][k-1]!=' '){counter++;}
                    if(Beginner_Board[j][k+1]!=' '){counter++;}
                    if(counter == 4) // if 4 borders are counted
                    {
                        Beginner_Board[j][k]=player; // Then place the letter of the player in the center of the box
			if (player=='A')
			{
				Beginner_Board_Colour[j][k]=1;
			}
			else
			{
				Beginner_Board_Colour[j][k]=-1;
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