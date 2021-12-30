#include <stdio.h>
#include "Check_For_Boxes_and_RE_Play.h"
#include "Print_Current_Board.h"
#include "Initialize_PvP_Beginner_Board.h"
#include "Struct_Player_Ingame_Info.h"
#include "Game_Info_Structure.h"
#include "Colours.h"
#include "Print_Current_Game_Status.h"
#include "Initialize_PvP_Beginner_Board_Colours.h"
#include "A_Check_For_Boxes_and_RE_Play.h"
#include "A_Print_Current_Board.h"
#include "A_Initialize_PvP_Advanced_Board.h"
#include "A_Struct_Player_Ingame_Info.h"
#include "A_Game_Info_Structure.h"
#include "A_Print_A_Current_Game_Status.h"
#include "A_Initialize_PvP_Advanced_Board_Colours.h"

int main()
{
    printf(CYAN "\t\t\t\t\t""******************* ""Welcome to \"Dots & Boxes Game\" PvP Mode *******************\n\n"
    "Please Choose The Choice Number of The difficulty level You want to Play.\n" RESET);
    printf(CYAN "-------------------------------------------------------------------------\n" RESET);
    printf(CYAN "For Beginner Mode Press 1 \nFor Advanced Mode Press 2\nEnter: " RESET);
    char d[2];
    scanf(" %s",&d);
    d[0] = (int)d[0] - 48; // Converting the ASCII Code to the decimal real value, notice that '0' in decimal = 48 ASCII Characters and so on.
    while(d[0] != 1 && d[0] != 2 || (int) d[1] >= 33 && (int) d[1] <= 127) // Checking that the user has entered only 1 Digit / Character.
    // To avoid the error that happens when the user enter 12 for example, the compiler will read 1 and choose 1
    // This should not happen, we should read 12 as 1 number, but since we are reading characters so we read only 1 digit.
    // So we must check that the second character is empty ! in other words there is no a printable character placed in it 
    // printable characters are from 33 - 127
    {
        printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
        printf(CYAN "For Beginner Mode Press 1 \nFor Advanced Mode Press 2\nEnter: " RESET);
        scanf(" %s",&d); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
        // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
        d[0] = (int)d[0] - 48;
    }
    if(d[0]==1)
    {
        int Beginner_Board[6][6]={{}}; // Initializing 6x6 Array
        Initialize_PvP_Beginner_Board(6,6,Beginner_Board);
        int Beginner_Board_Colour[6][6]={{}}; // Initializing The Elements Colour Array
        Intialize_PvP_Beginner_Board_Colour(6,6,Beginner_Board_Colour);
        int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
        int Borders = 12; // Game Should End after all available borders are placed.
        printf("\t\t\t\t\t""\x1b[32m""Welcome to \"Dots & Boxes Game\" Beginner Mode\n""\x1b[0m"); // Welcome Statement in green
        Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
        Print_Current_Game_Status(Current_Game);
    // --------------------------------- PvP_Beginner_Mode_Start ------------------------------------------
        while(Borders > 0)
        {
    // --------------------------------- Player_A's_Turn ------------------------------------------
            while(Player_1.Turn==1 && Borders > 0) // Player 1 Turn is True
            {
                int temp[2]={0,0}; // 1st -> Boxes Created, 2nd -> Turn
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ [AVOIDING CHARACTERS ERROR - CODE]
                char g[2];
                char f[2];
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 
                printf(RED "Player A's Turn\nEnter The Index in the form X(Row) Y(Column): " RESET);scanf(" %s %s",&g,&f); // Scanning the index
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 
                g[0] = (int)g[0] - 48; 
                f[0] = (int)f[0] - 48; 
                while(g[0] > 9 || g[0] < 0 || (int) g[1] >= 33 && (int) g[1] <= 127 || f[0] > 9 || f[0] <0 || (int) f[1] >= 33 && (int) f[1] <= 127)
                {
                    printf(CYAN "Error, Non-Available input was given, Please check that the input is with in the Board limits X[0-5] Y[0-5]\n");
                    printf(RED "Player A's Turn\nEnter The Index in the form X(Row) Y(Column): " RESET);
                    scanf(" %s %s",&g,&f);
                    // Scanning the index
                    // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                    // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                    g[0] = (int)g[0] - 48;
                    f[0] = (int)f[0] - 48;
                }
                x = g[0];
                y = f[0];
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                if(x>0 && y>0 && x<6 && y<6) 
                {
                    if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                    {
                        if(y%2==1) // Checking the Vertical Borders' Position.
                        {
                            if(Beginner_Board[x][y]==' ') // Checking the position is empty
                            {
                                printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                Beginner_Board[x][y]=186;
                                Beginner_Board_Colour[x][y]=1;
                                Player_2.Turn=1; // Giving the turn access to Player B
                                Player_1.Borders++;Current_Game.First_Player_Borders++;
                                Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp,Beginner_Board_Colour); // Checking For Created Boxes
                                Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                                Current_Game.Remaining_Boxes-=temp[0];
                                Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                Print_Current_Game_Status(Current_Game);
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
                    else if(y%2==0) // Checking The Horizontal Borders' Position.
                    {
                        if(Beginner_Board[x][y]==' ') // Checking The position is Empty.
                        {
                            printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                            Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                            Beginner_Board[x][y]='=';
                            Beginner_Board_Colour[x][y]=1;
                            Player_2.Turn=1; // Giving the turn access to Player B
                            Player_1.Borders++;Current_Game.First_Player_Borders++;
                            Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp,Beginner_Board_Colour); // Checking For Created Boxes
                            Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                            // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                            Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                            Current_Game.Remaining_Boxes-=temp[0];
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
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
    // --------------------------------- Player_B's_Turn ------------------------------------------
            while(Player_2.Turn==1 && Borders > 0) // Player 1 Turn is True
            {
                int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ [AVOIDING CHARACTERS ERROR - CODE]
                char g[2];
                char f[2];
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                printf(BLUE "Player B's Turn\nEnter The Index in the form X(Row) Y(Column): " RESET);scanf(" %s %s",&g,&f); // Scanning the index
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                g[0] = (int)g[0] - 48; 
                f[0] = (int)f[0] - 48; 
                while(g[0] > 9 || g[0] < 0 || (int) g[1] >= 33 && (int) g[1] <= 127 || f[0] > 9 || f[0] <0 || (int) f[1] >= 33 && (int) f[1] <= 127)
                {
                    printf(CYAN "Error, Non-Available input was given, Please check that the input is with in the Board limits X[0-5] Y[0-5]\n");
                    printf(BLUE "Player B's Turn\nEnter The Index in the form X(Row) Y(Column): " RESET);
                    scanf(" %s %s",&g,&f);
                    // Scanning the index
                    // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                    // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                    g[0] = (int)g[0] - 48;
                    f[0] = (int)f[0] - 48;
                }
                x = g[0];
                y = f[0];
                // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                if(x>0 && y>0 && x<6 && y<6) 
                {
                    if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                    {
                        if(y%2==1) // Checking the Vertical Borders' Position.
                        {
                            if(Beginner_Board[x][y]==' ') // Checking the position is empty
                            {
                                printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                Beginner_Board[x][y]=186;
                                Beginner_Board_Colour[x][y]=-1;
                                Player_2.Borders++;Current_Game.Second_Player_Borders++;
                                Player_1.Turn=1;
                                Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp,Beginner_Board_Colour);
                                Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                                // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                                Current_Game.Remaining_Boxes-=temp[0];
                                Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                Print_Current_Game_Status(Current_Game);
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
                    else if(y%2==0) // Checking The Horizontal Borders' Position.
                    {
                        if(Beginner_Board[x][y]==' ') // Checking The position is Empty.
                        {
                            printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                            Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                            Beginner_Board[x][y]='=';
                            Beginner_Board_Colour[x][y]=-1;
                            Player_2.Borders++;Current_Game.Second_Player_Borders++;
                            Player_1.Turn=1;
                            Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp,Beginner_Board_Colour);
                            Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                            // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                            Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                            Current_Game.Remaining_Boxes-=temp[0];
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
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
                else printf(CYAN "Position is out of range, Please Try again.\n" RESET);
            }
        }
        Print_Who_Won(Current_Game);
    // --------------------------------- PvP_Beginner_Mode_End ------------------------------------------
    } 
    else if(d[0]==2)
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
        A_Print_Who_Won(A_Current_Game);
    }
    else
    {
        printf(CYAN "Sorry, The number you have entered is not available, Please Try Again.\n" RESET);
    }
    return 0;
}
