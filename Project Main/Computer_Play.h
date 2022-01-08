/*
Module Description:
It's function to make computer play .
It takes arguments : dimensions of array , number of boxes , board.
*/

#ifndef COMPUTER_PLAY_H
#define COMPUTER_PLAY_H

void Computer_Play(int a, int b ,int boxes, int Board[][b],int Board_Colour[][b])
{
    int playing =0;
    c1:
    {
        for(int j=2 ; j<a; j=j+2) // j=[2,4,...]
        {
            for(int k=2;k<b;k=k+2)  // k=[2,4,...]
            {
                if(Board[j][k]==' ' ) // to check the box is empty or not.
                {
                    int counter=0;
                    if(Board[j-1][k]==' '){counter++;}
                    if(Board[j+1][k]==' '){counter++;}
                    if(Board[j][k-1]==' '){counter++;}
                    if(Board[j][k+1]==' '){counter++;} // to count how many boards are empty .
                    if(counter==1 ) // to make computer close a box.
                    {
                        if(Board[j-1][k]==' '){Board[j-1][k]='=';Board_Colour[j-1][k]=-1; playing++; break; }
                        else if(Board[j+1][k]==' '){Board[j+1][k]='=';Board_Colour[j+1][k]=-1;playing++;break; }
                        else if(Board[j][k-1]==' '){Board[j][k-1]=186;Board_Colour[j][k-1]=-1;playing++;break; }
                        else if(Board[j][k+1]==' '){Board[j][k+1]=186;Board_Colour[j][k+1]=-1;playing++;break; }
                        else goto c1;
                    }
                }
            }
        if(playing !=0) break; // once computer plays , it will go out from for loop.
        }
    
    }
    if(playing==0) // computer didn't play.
    {
    c2:   
    {
        for(int j=2 ; j<a; j=j+2) // j=[2,4,...]
        {
            for(int k=2;k<b;k=k+2)  // k=[2,4,...]
            {
                if(Board[j][k]==' ' ) // to check the box is empty or not.
                {
                    int counter=0;
                    if(Board[j-1][k]==' '){counter++;}
                    if(Board[j+1][k]==' '){counter++;}
                    if(Board[j][k-1]==' '){counter++;}
                    if(Board[j][k+1]==' '){counter++;} // to count how many boards are empty .
                    if(counter==3 ) // to make computer play if there is only 3 boards are empty.
                    {
                        if(Board[j-1][k]==' '){Board[j-1][k]='=';Board_Colour[j-1][k]=-1; playing++; break; }
                        else if(Board[j+1][k]==' '){Board[j+1][k]='=';Board_Colour[j+1][k]=-1;playing++;break; }
                        else if(Board[j][k-1]==' '){Board[j][k-1]=186;Board_Colour[j][k-1]=-1;playing++;break; }
                        else if(Board[j][k+1]==' '){Board[j][k+1]=186;Board_Colour[j][k+1]=-1;playing++;break; }
                        else goto c2;
                    }
                }
            }
        if(playing !=0) break; // once computer plays , it will go out from for loop.
        }
    }
    }
    if(playing==0) // computer didn't play.
    {
    c3:   
    {
        for(int j=2 ; j<a; j=j+2) // j=[2,4,...]
        {
            for(int k=2;k<b;k=k+2)  // k=[2,4,...]
            {
                if(Board[j][k]==' ' ) // to check the box is empty or not.
                {
                    int counter=0;
                    if(Board[j-1][k]==' '){counter++;}
                    if(Board[j+1][k]==' '){counter++;}
                    if(Board[j][k-1]==' '){counter++;}
                    if(Board[j][k+1]==' '){counter++;} // to count how many boards are empty .
                    if( counter==4) // to make computer play if there is zero boards.
                    {
                        if(Board[j-1][k]==' '){Board[j-1][k]='=';Board_Colour[j-1][k]=-1; playing++; break; }
                        else if(Board[j+1][k]==' '){Board[j+1][k]='=';Board_Colour[j+1][k]=-1;playing++;break; }
                        else if(Board[j][k-1]==' '){Board[j][k-1]=186;Board_Colour[j][k-1]=-1;playing++;break; }
                        else if(Board[j][k+1]==' '){Board[j][k+1]=186;Board_Colour[j][k+1]=-1;playing++;break; }
                        else goto c3;
                    }
                }
            }
        if(playing !=0) break; // once computer plays , it will go out from for loop.
        }
    }
    }
    if(playing==0) // if computer didn't play according to this technic , it will play in any available place.
    {
        for(int j=2 ; j<a; j=j+2)
        {
            for(int k=2;k<b;k=k+2)
            {
                if(Board[j-1][k]==' '){Board[j-1][k]='=';Board_Colour[j-1][k]=-1;}
                else if(Board[j+1][k]==' '){Board[j+1][k]='=';Board_Colour[j+1][k]=-1;}
                else if(Board[j][k-1]==' '){Board[j][k-1]=186;Board_Colour[j][k-1]=-1;}
                else if(Board[j][k+1]==' '){Board[j][k+1]=186;Board_Colour[j][k+1]=-1;}
            }
        }
    }
}


#endif