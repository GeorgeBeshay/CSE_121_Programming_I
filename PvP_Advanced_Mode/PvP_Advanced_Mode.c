#include <stdio.h>
#include "Colours.h"
#include "A_Check_For_Boxes_and_RE_Play.h"
#include "A_Print_Current_Board.h"
#include "A_Initialize_PvP_Advanced_Board.h"
#include "A_Struct_Player_Ingame_Info.h"
#include "A_Game_Info_Structure.h"
#include "A_Print_A_Current_Game_Status.h"
#include "A_Initialize_PvP_Advanced_Board_Colours.h"

int main()
{
    
    int Advanced_Board[12][12]={{}}; // Initializing 6x6 Array
    A_Initialize_PvP_Advamced_Board(12,12,Advanced_Board);
    int Advanced_Board_Colour[12][12]={{}};
    Intialize_PvP_Advanced_Board_Colour(12,12,Advanced_Board_Colour);
    int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
    int A_Borders = 60; // Game Should End after all available A_Borders are placed.
    A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
    A_Print_A_Current_Game_Status(A_Current_Game);
// --------------------------------- PvP_Advanced_Mode_Start ------------------------------------------
    while(A_Borders > 0)
    {
// --------------------------------- Player_A's_Turn ------------------------------------------
        while(A_Player_1.Turn==1 && A_Borders >0) // Player 1 Turn is True
        {
            int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
            printf(RED "Player A's Turn\nEnter The Index in the form X(Row) Y(Column): " RESET);scanf("%d %d",&x,&y); // Scanning the index
            if(x>0 && y>0 && x<12 && y<12) 
            {
                if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                {
                    if(y%2==1) // Checking the Vertical A_Borders' Position.
                    {
                        if(Advanced_Board[x][y]==' ') // Checking the position is empty
                        {
                            printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                            A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                            Advanced_Board[x][y]=186;
                            Advanced_Board_Colour[x][y]=1;
                            A_Player_2.Turn=1; // Giving the turn access to Player B
                            A_Player_1.Borders++;A_Current_Game.A_First_Player_Borders++;
                            A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'A',temp,Advanced_Board_Colour); // Checking For Created Boxes
                            A_Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                            // So player A will Replay, also A_Player_2.Turn will still have the value 1 waiting for its turn.
                            A_Player_1.Boxes+=temp[0];A_Current_Game.A_First_Player_Boxes+=temp[0]; // Adding created boxes
                            A_Current_Game.A_Remaining_Boxes-=temp[0];
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                        }
                        else // The position can be placed in it a border, but it is taken.
                        {
                            printf(CYAN "The Position you have chosen is already taken, Please Try again.\n" RESET);
                        }
                    }
                    else // Position Entered can't be placed in it a border (out of range / rows,column numbering)
                    {
                        printf(CYAN "Position Not Available, Please Try again\n" RESET);
                    }
                }
                else if(y%2==0) // Checking The Horizontal A_Borders' Position.
                {
                    if(Advanced_Board[x][y]==' ') // Checking The position is Empty.
                    {
                        printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                        A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                        Advanced_Board[x][y]='=';
                        Advanced_Board_Colour[x][y]=1;
                        A_Player_2.Turn=1; // Giving the turn access to Player B
                        A_Player_1.Borders++;A_Current_Game.A_First_Player_Borders++;
                        A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'A',temp,Advanced_Board_Colour); // Checking For Created Boxes
                        A_Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                        // So player A will Replay, also A_Player_2.Turn will still have the value 1 waiting for its turn.
                        A_Player_1.Boxes+=temp[0];A_Current_Game.A_First_Player_Boxes+=temp[0]; // Adding created boxes
                        A_Current_Game.A_Remaining_Boxes-=temp[0];
                        A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                        A_Print_A_Current_Game_Status(A_Current_Game);
                    }
                    else
                    {
                        printf(CYAN "The Position you have chosen is already taken, Please Try again.\n" CYAN);
                    }
                }
                else
                {
                    printf(CYAN "Wrong Position, Please Try again.\n" RESET);
                }
            }
            else 
            {
                printf(CYAN "Position is out of range, Please Try again.\n" RESET);
            }
        }
// --------------------------------- Player_B's_Turn ------------------------------------------
        while(A_Player_2.Turn==1 && A_Borders >0) // Player 1 Turn is True
        {
            int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
            printf(BLUE "Player B's Turn\nEnter The Index in the form X(Row) Y(Column): " RESET);scanf("%d %d",&x,&y); // Scanning the index
            if(x>0 && y>0 && x<12 && y<12) 
            {
                if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                {
                    if(y%2==1) // Checking the Vertical A_Borders' Position.
                    {
                        if(Advanced_Board[x][y]==' ') // Checking the position is empty
                        {
                            printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                            A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                            Advanced_Board[x][y]=186;
                            Advanced_Board_Colour[x][y]=-1;
                            A_Player_2.Borders++;A_Current_Game.A_Second_Player_Borders++;
                            A_Player_1.Turn=1;
                            A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'B',temp,Advanced_Board_Colour);
                            A_Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                            // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                            A_Player_2.Boxes+=temp[0];A_Current_Game.A_Second_Player_Boxes+=temp[0];
                            A_Current_Game.A_Remaining_Boxes-=temp[0];
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                        }
                        else // The position can be placed in it a border, but it is taken.
                        {
                            printf(CYAN "The Position you have chosen is already taken, Please Try again.\n" RESET);
                        }
                    }
                    else // Position Entered can't be placed in it a border (out of range / rows,column numbering)
                    {
                        printf(CYAN "Position Not Available, Please Try again\n" RESET);
                    }
                }
                else if(y%2==0) // Checking The Horizontal A_Borders' Position.
                {
                    if(Advanced_Board[x][y]==' ') // Checking The position is Empty.
                    {
                        printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                        A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                        Advanced_Board[x][y]='=';
                        Advanced_Board_Colour[x][y]=-1;
                        A_Player_2.Borders++;A_Current_Game.A_Second_Player_Borders++;
                        A_Player_1.Turn=1;
                        A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'B',temp,Advanced_Board_Colour);
                        A_Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                        A_Player_2.Boxes+=temp[0];A_Current_Game.A_Second_Player_Boxes+=temp[0];
                        A_Current_Game.A_Remaining_Boxes-=temp[0];
                        A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                        A_Print_A_Current_Game_Status(A_Current_Game);
                    }
                    else
                    {
                        printf(CYAN "The Position you have chosen is already taken, Please Try again.\n" RESET);
                    }
                }
                else
                {
                    printf(CYAN "Wrong Position, Please Try again.\n" RESET);
                }
            }
            else 
            {
                printf(CYAN "Position is out of range, Please Try again.\n" RESET);
            }
        }
    }
    return 0;
}