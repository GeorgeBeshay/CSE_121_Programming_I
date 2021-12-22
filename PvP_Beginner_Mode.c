#include <stdio.h>
#include "Check_For_Boxes_and_RE_Play.h"
#include "Print_Current_Board.h"
#include "Initialize_PvP_Beginner_Board.h"
#include "Struct_Player_Ingame_Info.h"
#include "Game_Info_Structure.h"
#include "Colours.h"
#include "Print_Current_Game_Status.h"

int main()
{
    int Beginner_Board[6][6]={{}}; // Initializing 6x6 Array
    Initialize_PvP_Beginner_Board(6,6,Beginner_Board);
    int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
    int Borders = 12; // Game Should End after all available borders are placed.
    printf("\t\t\t\t\t""\x1b[32m""Welcome to \"Dots & Boxes Game\"\n""\x1b[0m"); // Welcome Statement in green
    Print_Current_Board(6,6,Beginner_Board);
    Print_Current_Game_Status(Current_Game);
// --------------------------------- PvP_Beginner_Mode_Start ------------------------------------------
    while(Borders > 0)
    {
// --------------------------------- Player_A's_Turn ------------------------------------------
        while(Player_1.Turn==1 && Borders > 0) // Player 1 Turn is True
        {
            int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
            printf("Player A's Turn\nEnter The Index in the form X(Row) Y(Column): ");scanf("%d %d",&x,&y); // Scanning the index
            if(x>0 && y>0 && x<6 && y<6) 
            {
                if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                {
                    if(y%2==1) // Checking the Vertical Borders' Position.
                    {
                        if(Beginner_Board[x][y]==' ') // Checking the position is empty
                        {
                            printf("Position Available \"Vertical Dash\"\n"); 
                            Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                            Beginner_Board[x][y]='|';
                            Player_2.Turn=1; // Giving the turn access to Player B
                            Player_1.Borders++;Current_Game.First_Player_Borders++;
                            Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp); // Checking For Created Boxes
                            Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                            // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                            Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                            Current_Game.Remaining_Boxes-=temp[0];
                            Print_Current_Board(6,6,Beginner_Board);
                            Print_Current_Game_Status(Current_Game);
                        }
                        else // The position can be placed in it a border, but it is taken.
                        {
                            printf("The Position you have chosen is already taken, Please Try again.\n");
                        }
                    }
                    else // Position Entered can't be placed in it a border (out of range / rows,column numbering)
                    {
                        printf("Position Not Available, Please Try again\n");
                    }
                }
                else if(y%2==0) // Checking The Horizontal Borders' Position.
                {
                    if(Beginner_Board[x][y]==' ') // Checking The position is Empty.
                    {
                        printf("Position Available \"Horizontal Dash\"\n");
                        Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                        Beginner_Board[x][y]='-';
                        Player_2.Turn=1; // Giving the turn access to Player B
                        Player_1.Borders++;Current_Game.First_Player_Borders++;
                        Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp); // Checking For Created Boxes
                        Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                        Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                        Current_Game.Remaining_Boxes-=temp[0];
                        Print_Current_Board(6,6,Beginner_Board);
                        Print_Current_Game_Status(Current_Game);
                    }
                    else
                    {
                        printf("The Position you have chosen is already taken, Please Try again.\n");
                    }
                }
                else
                {
                    printf("Wrong Position, Please Try again.\n");
                }
            }
            else printf("Position is out of range, Please Try again.\n");
        }
// --------------------------------- Player_B's_Turn ------------------------------------------
        while(Player_2.Turn==1 && Borders > 0) // Player 1 Turn is True
        {
            int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
            printf("Player B's Turn\nEnter The Index in the form X(Row) Y(Column): ");scanf("%d %d",&x,&y); // Scanning the index
            if(x>0 && y>0 && x<6 && y<6) 
            {
                if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                {
                    if(y%2==1) // Checking the Vertical Borders' Position.
                    {
                        if(Beginner_Board[x][y]==' ') // Checking the position is empty
                        {
                            printf("Position Available \"Vertical Dash\"\n"); 
                            Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                            Beginner_Board[x][y]='|';
                            Player_2.Borders++;Current_Game.Second_Player_Borders++;
                            Player_1.Turn=1;
                            Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp);
                            Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                            // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                            Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                            Current_Game.Remaining_Boxes-=temp[0];
                            Print_Current_Board(6,6,Beginner_Board);
                            Print_Current_Game_Status(Current_Game);
                        }
                        else // The position can be placed in it a border, but it is taken.
                        {
                            printf("The Position you have chosen is already taken, Please Try again.\n");
                        }
                    }
                    else // Position Entered can't be placed in it a border (out of range / rows,column numbering)
                    {
                        printf("Position Not Available, Please Try again\n");
                    }
                }
                else if(y%2==0) // Checking The Horizontal Borders' Position.
                {
                    if(Beginner_Board[x][y]==' ') // Checking The position is Empty.
                    {
                        printf("Position Available \"Horizontal Dash\"\n");
                        Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                        Beginner_Board[x][y]='-';
                        Player_2.Borders++;Current_Game.Second_Player_Borders++;
                        Player_1.Turn=1;
                        Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp);
                        Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                        Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                        Current_Game.Remaining_Boxes-=temp[0];
                        Print_Current_Board(6,6,Beginner_Board);
                        Print_Current_Game_Status(Current_Game);
                    }
                    else
                    {
                        printf("The Position you have chosen is already taken, Please Try again.\n");
                    }
                }
                else
                {
                    printf("Wrong Position, Please Try again.\n");
                }
            }
            else printf("Position is out of range, Please Try again.\n");
        }
    }
    Print_Current_Game_Status(Current_Game);
    Print_Who_Won(Current_Game);
// --------------------------------- PvP_Beginner_Mode_End ------------------------------------------
    return 0;
}