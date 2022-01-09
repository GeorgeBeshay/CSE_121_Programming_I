#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>

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
#include "Undo_Redo_Module.h"
#include "Computer_Play.h"
#include "Top_10_List_Module.h"
#include "Export_Data.h"

int main()
{
    system("cls");
    time_t start,end;
    printf(CYAN "\t\t\t\t\t""******************* ""Welcome to \"Dots & Boxes Game\" PvP Mode *******************\n\n");
    printf(CYAN "Please Type the Number corresponding to your choice from the following list:\n"
    "1] PvP Mode.\n"
    "2] PvC Mode.\n"
    "3] Top 10 List.\n"
    "Choice Number: "RESET);
    char o[2];
    scanf(" %s",&o);
    o[0]=(int)o[0]-48;
    while(o[0]!=1 && o[0]!=2 && o[0]!=3 || (int)o[1]>=33 && (int)o[1]<=127)
    {
        printf(CYAN "Error, Please Choose one of given choices ONLY.\n");
        printf(CYAN "Please Type the Number corresponding to your choice from the following list:\n"
        "1] PvP Mode.\n"
        "2] PvC Mode.\n"
        "3] Top 10 List.\n"
        "Choice Number: "RESET);
        scanf(" %s",&o);
        o[0]=(int)o[0]-48;
    }
    if(o[0]==1)
    {
        system("cls");
        printf(CYAN "PvP Mode Has Been Chosen.\n");
        printf(CYAN "Please Type The Choice Number of The difficulty level You want to Play.\n" RESET);
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
            char yy[2];
            printf(CYAN "PvP_Beginner_Mode Has been chosen.\n1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy);
            yy[0] = (int)yy[0] - 48;
            while(yy[0] != 1 && yy[0] != 2 || (int) yy[1] >= 33 && (int) yy[1] <= 127)
            {
            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
            printf(CYAN "1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
            yy[0] = (int)yy[0] - 48;
            }
            system("cls");
            int Beginner_Board[6][6]={{}}; // Initializing 6x6 Array
            Initialize_PvP_Beginner_Board(6,6,Beginner_Board);
            int Beginner_Board_Colour[6][6]={{}}; // Initializing The Elements Colour Array
            Intialize_PvP_Beginner_Board_Colour(6,6,Beginner_Board_Colour);
            Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
            Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
            int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
            int Borders = 12; // Game Should End after all available borders are placed.
            printf("\t\t\t\t\t""\x1b[32m""Welcome to \"Dots & Boxes Game\" Beginner Mode\n""\x1b[0m"); // Welcome Statement in green
            if(yy[0]==2)
            {
                printf(CYAN"Choose one of the following files to load your game data from.\n"
                                    "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:"RESET);
                char www[2];
                scanf("%s",&www);
                www[0]=(int)www[0]-48;
                while(www[0] != 1 && www[0] != 2 && www[0] != 3 || (int) www[1] >= 33 && (int) www[1] <= 127)
                {
                    printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                    printf(CYAN "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:" RESET );
                    scanf("%s",&www); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                    // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                    www[0] = (int)www[0] - 48;
                }
                int temptemp[9];
                Import_Data_Beginner(Beginner_Board,Beginner_Board_Colour,www[0],temptemp);
                Current_Game.First_Player_Borders=temptemp[4];
                Current_Game.First_Player_Boxes=temptemp[5];
                Current_Game.Remaining_Borders=temptemp[0];
                Borders=temptemp[0];
                Current_Game.Remaining_Boxes=temptemp[1];
                Current_Game.Second_Player_Borders=temptemp[6];
                Current_Game.Second_Player_Boxes=temptemp[7];
                Player_1.Turn=temptemp[2];
                Player_2.Turn=temptemp[3];
                Player_1.Borders=temptemp[4];
                Player_1.Boxes=temptemp[5];
                Player_2.Borders=temptemp[6];
                Player_2.Boxes=temptemp[7];
                Board_Number=temptemp[8];
                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                URB_GS_PI_Current.URB_FP_Borders[Board_Number]=temptemp[4];
                URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=temptemp[5];
                URB_GS_PI_Current.URB_P1_Turn[Board_Number]=temptemp[2];
                URB_GS_PI_Current.URB_P2_Turn[Board_Number]=temptemp[3];
                URB_GS_PI_Current.URB_SP_Borders[Board_Number]=temptemp[6];
                URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=temptemp[7];
                URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=temptemp[0];
                URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=temptemp[1];
            }
            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
            Print_Current_Game_Status(Current_Game);
            char Player_A_Name[100];
            char Player_B_Name[100];
            printf(CYAN "Please Enter Player A Name (FIRST NAME ONLY): " RESET);scanf("%s",Player_A_Name);
            printf(CYAN "Please Enter Player B Name (FIRST NAME ONLY): " RESET);scanf("%s",Player_B_Name);
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
                    printf(RED "Player A's Turn\n");
                    if(Current_Game.Remaining_Borders<12)
                    {
                        printf("For UNDO Type \"U U\"\nFor REDO Type \"R R\"\nTo Exit the Game Type \"E E\"\n");
                    }
                    printf("Enter The Index in the form X(Row) Y(Column): " RESET);start = time(NULL);scanf(" %s %s",&g,&f); // Scanning the index
                    end = time(NULL);
                    // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 
                    g[0] = (int)g[0] - 48; 
                    f[0] = (int)f[0] - 48; 
                    while(g[0] > 9 && (g[0]!=37 && g[0]!=34 && g[0]!=21) || g[0] < 0 || (int) g[1] >= 33 && (int) g[1] <= 127 || f[0] > 9 && (f[0]!=37 && f[0]!=34 && f[0]!=21) || f[0] <0 || (int) f[1] >= 33 && (int) f[1] <= 127)
                    {
                        printf(CYAN "Error, Non-Available input was given, Please check that the input is with in the Board limits X[0-5] Y[0-5]\n");
                        printf(RED "Player A's Turn\n");
                        if(Current_Game.Remaining_Borders<12)
                        {
                            printf("For UNDO Type \"U U\"\nFor REDO Type \"R R\"\n");
                        }
                        printf("Enter The Index in the form X(Row) Y(Column): " RESET);
                        start = time(NULL);
                        scanf(" %s %s",&g,&f);
                        end = time(NULL);
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
                                    Available_REDOs=0;
                                    printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                    Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                    Beginner_Board[x][y]=186;
                                    Beginner_Board_Colour[x][y]=1;
                                    Player_1.Borders++;Current_Game.First_Player_Borders++;
                                    Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp,Beginner_Board_Colour); // Checking For Created Boxes
                                    Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                    if (Player_1.Turn==0){Player_2.Turn=1;} // Giving the turn access to Player B
                                    // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                    Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                                    Current_Game.Remaining_Boxes-=temp[0];
                                    Board_Number++;
                                    Availabe_UNDOs++;
                                    Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                                    Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                                    // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                                    // FROM HERE
                                    URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                                    URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                                    URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                                    URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                                    URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                                    URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                                    URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                                    URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                                    // TO HERE
                                    system("cls");
                                    Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                    Print_Current_Game_Status(Current_Game);
                                    printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                                Available_REDOs=0;
                                printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                                Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                Beginner_Board[x][y]='=';
                                Beginner_Board_Colour[x][y]=1;
                                Player_1.Borders++;Current_Game.First_Player_Borders++;
                                Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp,Beginner_Board_Colour); // Checking For Created Boxes
                                Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                if (Player_1.Turn==0){Player_2.Turn=1;} // Giving the turn access to Player B
                                // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                                Current_Game.Remaining_Boxes-=temp[0];
                                Board_Number++;
                                Availabe_UNDOs++;
                                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                                // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                                // FROM HERE
                                URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                                URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                                URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                                URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                                URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                                URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                                URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                                URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                                // TO HERE
                                system("cls");
                                Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                Print_Current_Game_Status(Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                    else if(x==34 && y==34)
                    {
                        if(Available_REDOs>0)
                        {
                            Borders--;
                            Board_Number++;
                            Availabe_UNDOs++;
                            Available_REDOs--;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN"ERROR: No Available Move can be REdone.\n"RESET);
                        }
                    }
                    else if(x==37 && y==37)
                    {
                        if(Availabe_UNDOs>0)
                        {
                            Borders++;
                            Board_Number--;
                            Availabe_UNDOs--;
                            Available_REDOs++;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be undone.\n"RESET);
                        }
                    }
                    else if(x==21 && y==21)
                    {
                        system("cls");
                        printf(CYAN "Type in the choice number:\n1]Save and Exit\n2]Exit without Saving\nChoice:" RESET );
                        char w[2];
                        scanf("%s",&w);
                        w[0]=(int)w[0]-48;
                        while(w[0] != 1 && w[0] != 2 || (int) w[1] >= 33 && (int) w[1] <= 127)
                        {
                            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
                            printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                            scanf("%s",&w); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                            w[0] = (int)w[0] - 48;
                        }
                        if (w[0]==1)
                        {
                            printf(CYAN"Choose one of the following files to save your game data in.\n"
                                    "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:"RESET);
                            char ww[2];
                            scanf("%s",&ww);
                            ww[0]=(int)ww[0]-48;
                            while(ww[0] != 1 && ww[0] != 2 && ww[0] != 3 || (int) ww[1] >= 33 && (int) ww[1] <= 127)
                            {
                                printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                                printf(CYAN "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:" RESET );
                                scanf("%s",&ww); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                                // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                                ww[0] = (int)ww[0] - 48;
                            }
                            int temptemp[9]={Current_Game.Remaining_Borders,Current_Game.Remaining_Boxes,
                                            Player_1.Turn,Player_2.Turn,
                                            Player_1.Borders,Player_1.Boxes,
                                            Player_2.Borders,Player_2.Boxes,Board_Number};
                            Export_Data_Beginner(Beginner_Board,Beginner_Board_Colour,ww[0],temptemp);
                            printf(CYAN "DATA SAVED\n" RESET );exit(0);
                        }
                        else 
                        {
                            printf(CYAN"Data not saved.\n"RESET);exit(0);
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
                    printf(BLUE "Player B's Turn\n");
                    printf("For UNDO Type \"U U\"\nFor REDO Type \"R R\"\nTo Exit the Game Type \"E E\"\n");
                    printf("Enter The Index in the form X(Row) Y(Column): " RESET);start = time(NULL);scanf(" %s %s",&g,&f); // Scanning the index
                    end = time(NULL);
                    // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                    g[0] = (int)g[0] - 48; 
                    f[0] = (int)f[0] - 48; 
                    while(g[0] > 9 && (g[0]!=37 && g[0]!=34 && g[0]!=21) || g[0] < 0 || (int) g[1] >= 33 && (int) g[1] <= 127 || f[0] > 9 && (f[0]!=37 && f[0]!=34 && f[0]!=21) || f[0] <0 || (int) f[1] >= 33 && (int) f[1] <= 127)
                    {
                        printf(CYAN "Error, Non-Available input was given, Please check that the input is with in the Board limits X[0-5] Y[0-5]\n");
                        printf(BLUE "Player B's Turn\n");
                        printf("For UNDO Type \"U U\"\nFor REDO Type \"R R\"\n");
                        printf("Enter The Index in the form X(Row) Y(Column): " RESET);
                        start=time(NULL);
                        scanf(" %s %s",&g,&f);
                        end = time(NULL);
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
                                    Available_REDOs=0;
                                    printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                    Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                    Beginner_Board[x][y]=186;
                                    Beginner_Board_Colour[x][y]=-1;
                                    Player_2.Borders++;Current_Game.Second_Player_Borders++;
                                    Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp,Beginner_Board_Colour);
                                    Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                                    if(Player_2.Turn==0){Player_1.Turn=1;}
                                    // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                    Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                                    Current_Game.Remaining_Boxes-=temp[0];
                                    Board_Number++;
                                    Availabe_UNDOs++;
                                    Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                                    Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                                    // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                                    // From Here
                                    URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                                    URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                                    URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                                    URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                                    URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                                    URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                                    URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                                    URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                                    // To Here
                                    system("cls");
                                    Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                    Print_Current_Game_Status(Current_Game);
                                    printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                                Available_REDOs=0;
                                printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                                Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                Beginner_Board[x][y]='=';
                                Beginner_Board_Colour[x][y]=-1;
                                Player_2.Borders++;Current_Game.Second_Player_Borders++;
                                Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp,Beginner_Board_Colour);
                                Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                                if(Player_2.Turn==0){Player_1.Turn=1;}
                                // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                                Current_Game.Remaining_Boxes-=temp[0];
                                Board_Number++;
                                Availabe_UNDOs++;
                                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                                // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                                // From Here
                                URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                                URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                                URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                                URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                                URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                                URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                                URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                                URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                                // To here
                                system("cls");
                                Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                Print_Current_Game_Status(Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                    else if(x==34 && y==34)
                    {
                        if(Available_REDOs>0)
                        {
                            Borders--;
                            Board_Number++;
                            Availabe_UNDOs++;
                            Available_REDOs--;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be REdone.\n" RESET);
                        }
                    }
                    else if(x==37 && y==37)
                    {
                        if(Availabe_UNDOs>0)
                        {
                            Borders++;
                            Board_Number--;
                            Availabe_UNDOs--;
                            Available_REDOs++;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be undone.\n" RESET);
                        }
                    }
                    else if (x==21 && y==21)
                    {
                        system("cls");
                        printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                        char w[2];
                        scanf("%s",&w);
                        w[0]=(int)w[0]-48;
                        while(w[0] != 1 && w[0] != 2 || (int) w[1] >= 33 && (int) w[1] <= 127)
                        {
                            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
                            printf(CYAN "Type in the choice number:\n1]Save and Exit\n2]Exit without Saving\nChoice:" RESET );
                            scanf("%s",&w); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                            w[0] = (int)w[0] - 48;
                        }
                        if (w[0]==1)
                        {
                            printf(CYAN"Choose one of the following files to save your game data in.\n"
                                    "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:"RESET);
                            char ww[2];
                            scanf("%s",&ww);
                            ww[0]=(int)ww[0]-48;
                            while(ww[0] != 1 && ww[0] != 2 && ww[0] != 3 || (int) ww[1] >= 33 && (int) ww[1] <= 127)
                            {
                                printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                                printf(CYAN "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:" RESET );
                                scanf("%s",&ww); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                                // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                                ww[0] = (int)ww[0] - 48;
                            }
                            int temptemp[9]={Current_Game.Remaining_Borders,Current_Game.Remaining_Boxes,
                                            Player_1.Turn,Player_2.Turn,
                                            Player_1.Borders,Player_1.Boxes,
                                            Player_2.Borders,Player_2.Boxes,Board_Number};
                            Export_Data_Beginner(Beginner_Board,Beginner_Board_Colour,ww[0],temptemp);
                            printf(CYAN "DATA SAVED\n" RESET );exit(0);
                        }
                        else 
                        {
                            printf(CYAN"Data not saved.\n"RESET);exit(0);
                        }
                    }
                    else 
                    {
                        printf(CYAN "Position is out of range, Please Try again.\n" RESET);
                    }
                }
            }
            Print_Who_Won(Current_Game);
            Import_Beginner_Top_10_List();
            Append_New_User_And_Arrange(Player_A_Name,Player_1.Boxes);
            Append_New_User_And_Arrange(Player_B_Name,Player_2.Boxes);
            Export_Beginner_Top_10_List();
            printf(CYAN"Score Has Been updated for the 2 players !!\nCheck it from the $ Main Menu > Top 10 List $ \n"RESET);
        // --------------------------------- PvP_Beginner_Mode_End ------------------------------------------
        } 
        else if(d[0]==2)
        {
            char yy[2];
            printf(CYAN "PvP_Advanced_Mode Has been chosen.\n1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy);
            yy[0] = (int)yy[0] - 48;
            while(yy[0] != 1 && yy[0] != 2 || (int) yy[1] >= 33 && (int) yy[1] <= 127)
            {
            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
            printf(CYAN "1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
            yy[0] = (int)yy[0] - 48;
            }
            system("cls");
            int Advanced_Board[12][12]={{}}; // Initializing 6x6 Array
            A_Initialize_PvP_Advamced_Board(12,12,Advanced_Board);
            int Advanced_Board_Colour[12][12]={{}};
            Intialize_PvP_Advanced_Board_Colour(12,12,Advanced_Board_Colour);
            A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
            A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
            int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
            int A_Borders = 60; // Game Should End after all available A_Borders are placed.
            printf("\t\t\t\t\t""\x1b[32m""Welcome to \"Dots & Boxes Game\" Advanced Mode\n""\x1b[0m"); // Welcome Statement in green
            if(yy[0]==2)
            {
                printf(CYAN"Choose one of the following files to load your game data from.\n"
                                    "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:"RESET);
                char www[2];
                scanf("%s",&www);
                www[0]=(int)www[0]-48;
                while(www[0] != 1 && www[0] != 2 && www[0] != 3 || (int) www[1] >= 33 && (int) www[1] <= 127)
                {
                    printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                    printf(CYAN "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:" RESET );
                    scanf("%s",&www); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                    // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                    www[0] = (int)www[0] - 48;
                }
                int temptemp[9];
                Import_Data_Advanced(Advanced_Board,Advanced_Board_Colour,www[0],temptemp);
                A_Current_Game.A_First_Player_Borders=temptemp[4];
                A_Current_Game.A_First_Player_Boxes=temptemp[5];
                A_Current_Game.A_Remaining_Borders=temptemp[0];
                A_Borders=temptemp[0];
                A_Current_Game.A_Remaining_Boxes=temptemp[1];
                A_Current_Game.A_Second_Player_Borders=temptemp[6];
                A_Current_Game.A_Second_Player_Boxes=temptemp[7];
                A_Player_1.Turn=temptemp[2];
                A_Player_2.Turn=temptemp[3];
                A_Player_1.Borders=temptemp[4];
                A_Player_1.Boxes=temptemp[5];
                A_Player_2.Borders=temptemp[6];
                A_Player_2.Boxes=temptemp[7];
                A_Board_Number=temptemp[8];
                Copy_2D_To_3D(6,6,13,Board_Number,Advanced_Board,Advanced_Board_3D);
                Copy_2D_To_3D(6,6,13,Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=temptemp[4];
                URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=temptemp[5];
                URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=temptemp[2];
                URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=temptemp[3];
                URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=temptemp[6];
                URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=temptemp[7];
                URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=temptemp[0];
                URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=temptemp[1];
            }
            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
            A_Print_A_Current_Game_Status(A_Current_Game);
            char A_Player_A_Name[100];
            char A_Player_B_Name[100];
            printf(CYAN "Please Enter Player A Name (FIRST NAME ONLY): " RESET);scanf("%s",A_Player_A_Name);
            printf(CYAN "Please Enter Player B Name (FIRST NAME ONLY): " RESET);scanf("%s",A_Player_B_Name);
        // --------------------------------- PvP_Advanced_Mode_Start ------------------------------------------
            while(A_Borders > 0)
            {
        // --------------------------------- Player_A's_Turn ------------------------------------------
                while(A_Player_1.Turn==1 && A_Borders >0) // Player 1 Turn is True
                {
                    int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
                    printf(RED "Player A's Turn\n");
                    if(A_Current_Game.A_Remaining_Borders<60)
                    {
                        printf("For UNDO Type \"20 20\"\nFor REDO Type \"30 30\"\nTo Exit the Game Type \"50 50\"\n");
                    }
                    printf("Enter The Index in the form X(Row) Y(Column): " RESET);start=time(NULL);scanf("%d %d",&x,&y);end=time(NULL); // Scanning the index
                    if(x>0 && y>0 && x<12 && y<12) 
                    {
                        if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                        {
                            if(y%2==1) // Checking the Vertical A_Borders' Position.
                            {
                                if(Advanced_Board[x][y]==' ') // Checking the position is empty
                                {
                                    A_Available_REDOs=0;
                                    printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                    A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                                    Advanced_Board[x][y]=186;
                                    Advanced_Board_Colour[x][y]=1;
                                    A_Player_1.Borders++;A_Current_Game.A_First_Player_Borders++;
                                    A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'A',temp,Advanced_Board_Colour); // Checking For Created Boxes
                                    A_Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                    if(A_Player_1.Turn==0)
                                    {
                                        A_Player_2.Turn=1;
                                    }
                                    // So player A will Replay, also A_Player_2.Turn will still have the value 1 waiting for its turn.
                                    A_Player_1.Boxes+=temp[0];A_Current_Game.A_First_Player_Boxes+=temp[0]; // Adding created boxes
                                    A_Current_Game.A_Remaining_Boxes-=temp[0];
                                    A_Board_Number++;
                                    A_Availabe_UNDOs++;
                                    A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                                    A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                                    // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                                    // From Here
                                    URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                                    URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                                    URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                                    URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                                    URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                                    URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                                    URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                                    URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                                    // To Here
                                    system("cls");
                                    A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                                    A_Print_A_Current_Game_Status(A_Current_Game);
                                    printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                                A_Available_REDOs=0;
                                printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                                A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                                Advanced_Board[x][y]='=';
                                Advanced_Board_Colour[x][y]=1;
                                A_Player_1.Borders++;A_Current_Game.A_First_Player_Borders++;
                                A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'A',temp,Advanced_Board_Colour); // Checking For Created Boxes
                                A_Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                if(A_Player_1.Turn==0)
                                {
                                    A_Player_2.Turn=1;
                                }
                                // So player A will Replay, also A_Player_2.Turn will still have the value 1 waiting for its turn.
                                A_Player_1.Boxes+=temp[0];A_Current_Game.A_First_Player_Boxes+=temp[0]; // Adding created boxes
                                A_Current_Game.A_Remaining_Boxes-=temp[0];
                                A_Board_Number++;
                                A_Availabe_UNDOs++;
                                A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                                A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                                // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                                // From Here
                                URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                                URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                                URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                                URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                                URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                                URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                                URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                                URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                                // To Here
                                system("cls");
                                A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                                A_Print_A_Current_Game_Status(A_Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                    else if(x==30 && y==30)
                    {
                        if(A_Available_REDOs>0)
                        {
                            A_Board_Number++;
                            A_Availabe_UNDOs++;
                            A_Available_REDOs--;
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be REdone.\n"RESET);
                        }
                    }
                    else if(x==20 && y==20)
                    {
                        if(A_Availabe_UNDOs>0)
                        {
                            A_Board_Number--;
                            A_Availabe_UNDOs--;
                            A_Available_REDOs++;
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN"ERROR: No Available Move can be undone.\n"RESET);
                        }
                    }
                    else if(x==50 && y==50)
                    {
                        system("cls");
                        printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                        char w[2];
                        scanf("%s",&w);
                        w[0]=(int)w[0]-48;
                        while(w[0] != 1 && w[0] != 2 || (int) w[1] >= 33 && (int) w[1] <= 127)
                        {
                            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
                            printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                            scanf("%s",&w); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                            w[0] = (int)w[0] - 48;
                        }
                        if (w[0]==1)
                        {
                            printf(CYAN"Choose one of the following files to save your game data in.\n"
                                    "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:"RESET);
                            char ww[2];
                            scanf("%s",&ww);
                            ww[0]=(int)ww[0]-48;
                            while(ww[0] != 1 && ww[0] != 2 && ww[0] != 3 || (int) ww[1] >= 33 && (int) ww[1] <= 127)
                            {
                                printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                                printf(CYAN "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:" RESET );
                                scanf("%s",&ww); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                                // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                                ww[0] = (int)ww[0] - 48;
                            }
                            int temptemp[9]={A_Current_Game.A_Remaining_Borders,A_Current_Game.A_Remaining_Boxes,
                                            A_Player_1.Turn,A_Player_2.Turn,
                                            A_Player_1.Borders,A_Player_1.Boxes,
                                            A_Player_2.Borders,A_Player_2.Boxes,A_Board_Number};
                            Export_Data_Advanced(Advanced_Board,Advanced_Board_Colour,ww[0],temptemp);
                            printf(CYAN "DATA SAVED\n" RESET );exit(0);
                        }
                        else 
                        {
                            printf(CYAN"Data not saved.\n"RESET);exit(0);
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
                    printf(BLUE "Player B's Turn\n");
                    printf("For UNDO Type \"20 20\"\nFor REDO Type \"30 30\"\nTo Exit the Game Type \"50 50\"\n");
                    printf("Enter The Index in the form X(Row) Y(Column): " RESET);start=time(NULL);scanf("%d %d",&x,&y);end=time(NULL); // Scanning the index
                    if(x>0 && y>0 && x<12 && y<12) 
                    {
                        if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                        {
                            if(y%2==1) // Checking the Vertical A_Borders' Position.
                            {
                                if(Advanced_Board[x][y]==' ') // Checking the position is empty
                                {
                                    A_Available_REDOs=0;
                                    printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                    A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                                    Advanced_Board[x][y]=186;
                                    Advanced_Board_Colour[x][y]=-1;
                                    A_Player_2.Borders++;A_Current_Game.A_Second_Player_Borders++;
                                    A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'B',temp,Advanced_Board_Colour);
                                    A_Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                                    if(A_Player_2.Turn==0)
                                    {
                                        A_Player_1.Turn=1;
                                    }
                                    // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                    A_Player_2.Boxes+=temp[0];A_Current_Game.A_Second_Player_Boxes+=temp[0];
                                    A_Current_Game.A_Remaining_Boxes-=temp[0];
                                    A_Board_Number++;
                                    A_Availabe_UNDOs++;
                                    A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                                    A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                                    // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                                    // From Here
                                    URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                                    URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                                    URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                                    URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                                    URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                                    URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                                    URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                                    URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                                    // To Here
                                    system("cls");
                                    A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                                    A_Print_A_Current_Game_Status(A_Current_Game);
                                    printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                                A_Available_REDOs=0;
                                printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                                A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                                Advanced_Board[x][y]='=';
                                Advanced_Board_Colour[x][y]=-1;
                                A_Player_2.Borders++;A_Current_Game.A_Second_Player_Borders++;
                                A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'B',temp,Advanced_Board_Colour);
                                A_Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                                if(A_Player_2.Turn==0)
                                {
                                    A_Player_1.Turn=1;
                                }
                                // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                A_Player_2.Boxes+=temp[0];A_Current_Game.A_Second_Player_Boxes+=temp[0];
                                A_Current_Game.A_Remaining_Boxes-=temp[0];
                                A_Board_Number++;
                                A_Availabe_UNDOs++;
                                A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                                A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                                // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                                // From Here
                                URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                                URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                                URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                                URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                                URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                                URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                                URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                                URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                                // To Here
                                system("cls");
                                A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                                A_Print_A_Current_Game_Status(A_Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
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
                    else if(x==30 && y==30)
                    {
                        if(A_Available_REDOs>0)
                        {
                            A_Board_Number++;
                            A_Availabe_UNDOs++;
                            A_Available_REDOs--;
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be REdone.\n"RESET);
                        }
                    }
                    else if(x==20 && y==20)
                    {
                        if(A_Availabe_UNDOs>0)
                        {
                            A_Board_Number--;
                            A_Availabe_UNDOs--;
                            A_Available_REDOs++;
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                        }
                        else
                        {
                            printf(CYAN"ERROR: No Available Move can be undone.\n"RESET);
                        }
                    }
                    else if(x==50 && y==50)
                    {
                        system("cls");
                        printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                        char w[2];
                        scanf("%s",&w);
                        w[0]=(int)w[0]-48;
                        while(w[0] != 1 && w[0] != 2 || (int) w[1] >= 33 && (int) w[1] <= 127)
                        {
                            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
                            printf(CYAN "Type in the choice number:\n1]Save and Exit\n2]Exit without Saving\nChoice:" RESET );
                            scanf("%s",&w); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                            w[0] = (int)w[0] - 48;
                        }
                        if (w[0]==1)
                        {
                            printf(CYAN"Choose one of the following files to save your game data in.\n"
                                    "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:"RESET);
                            char ww[2];
                            scanf("%s",&ww);
                            ww[0]=(int)ww[0]-48;
                            while(ww[0] != 1 && ww[0] != 2 && ww[0] != 3 || (int) ww[1] >= 33 && (int) ww[1] <= 127)
                            {
                                printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                                printf(CYAN "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:" RESET );
                                scanf("%s",&ww); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                                // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                                ww[0] = (int)ww[0] - 48;
                            }
                            int temptemp[9]={A_Current_Game.A_Remaining_Borders,A_Current_Game.A_Remaining_Boxes,
                                            A_Player_1.Turn,A_Player_2.Turn,
                                            A_Player_1.Borders,A_Player_1.Boxes,
                                            A_Player_2.Borders,A_Player_2.Boxes,A_Board_Number};
                            Export_Data_Advanced(Advanced_Board,Advanced_Board_Colour,ww[0],temptemp);
                            printf(CYAN "DATA SAVED\n" RESET );exit(0);
                        }
                        else 
                        {
                            printf(CYAN"Data not saved.\n"RESET);exit(0);
                        }
                    }
                    else 
                    {
                        printf(CYAN "Position is out of range, Please Try again.\n" RESET);
                    }
                }
            }
            A_Print_Who_Won(A_Current_Game);
            Import_Advanced_Top_10_List();
            A_Append_New_User_And_Arrange(A_Player_A_Name,A_Player_1.Boxes);
            A_Append_New_User_And_Arrange(A_Player_B_Name,A_Player_2.Boxes);
            Export_Advanced_Top_10_List();
            printf(CYAN"Score Has Been updated for the 2 players !!\nCheck it from the $ Main Menu > Top 10 List $ \n"RESET);
        }
        else
        {
            printf(CYAN "Sorry, The number you have entered is not available, Please Try Again.\n" RESET);
        }
    }
    // ----------------------------------------- PvC Mode Start ------------------------------------------
    if (o[0]==2)
    {
        system("cls");
        printf(CYAN "PvC Mode Has Been Chosen.\n" RESET);
        printf(CYAN "Please Type The Choice Number of The difficulty level You want to Play.\n" RESET);
        printf(CYAN "-------------------------------------------------------------------------\n" RESET);
        printf(CYAN "For Beginner Mode Press 1 \nFor Advanced Mode Press 2\nChoice Number: " RESET);
        char o[2];
        scanf(" %s",&o);
        o[0]=(int)o[0]-48;
        while(o[0]!=1 && o[0]!=2 || (int)o[1]>=33 && (int)o[1]<=127)
        {
            printf(CYAN "Error, Please Choose one of given choices ONLY.\n");
            printf(CYAN "For Beginner Mode Press 1 \nFor Advanced Mode Press 2\nEnter: " RESET);
            scanf(" %s",&o);
            o[0]=(int)o[0]-48;
        }
        if(o[0]==1)
        {
            char yy[2];
            printf(CYAN "PvC_Beginner_Mode Has been chosen.\n1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy);
            yy[0] = (int)yy[0] - 48;
            while(yy[0] != 1 && yy[0] != 2 || (int) yy[1] >= 33 && (int) yy[1] <= 127)
            {
            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
            printf(CYAN "1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
            yy[0] = (int)yy[0] - 48;
            }
            system("cls");
            int Beginner_Board[6][6]={{}}; // Initializing 6x6 Array
            Initialize_PvP_Beginner_Board(6,6,Beginner_Board);
            int Beginner_Board_Colour[6][6]={{}}; // Initializing The Elements Colour Array
            Intialize_PvP_Beginner_Board_Colour(6,6,Beginner_Board_Colour);
            Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
            Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
            int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
            int Borders = 12; // Game Should End after all available borders are placed.
            printf("\t\t\t\t\t""\x1b[32m""Welcome to \"Dots & Boxes Game\" Beginner Mode\n""\x1b[0m"); // Welcome Statement in green
            if(yy[0]==2)
            {
                printf(CYAN"Choose one of the following files to load your game data from.\n"
                                    "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:"RESET);
                char www[2];
                scanf("%s",&www);
                www[0]=(int)www[0]-48;
                while(www[0] != 1 && www[0] != 2 && www[0] != 3 || (int) www[1] >= 33 && (int) www[1] <= 127)
                {
                    printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                    printf(CYAN "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:" RESET );
                    scanf("%s",&www); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                    // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                    www[0] = (int)www[0] - 48;
                }
                int temptemp[9];
                Import_Data_Beginner(Beginner_Board,Beginner_Board_Colour,www[0],temptemp);
                Current_Game.First_Player_Borders=temptemp[4];
                Current_Game.First_Player_Boxes=temptemp[5];
                Current_Game.Remaining_Borders=temptemp[0];
                Borders=temptemp[0];
                Current_Game.Remaining_Boxes=temptemp[1];
                Current_Game.Second_Player_Borders=temptemp[6];
                Current_Game.Second_Player_Boxes=temptemp[7];
                Player_1.Turn=temptemp[2];
                Player_2.Turn=temptemp[3];
                Player_1.Borders=temptemp[4];
                Player_1.Boxes=temptemp[5];
                Player_2.Borders=temptemp[6];
                Player_2.Boxes=temptemp[7];
                Board_Number=temptemp[8];
                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                URB_GS_PI_Current.URB_FP_Borders[Board_Number]=temptemp[4];
                URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=temptemp[5];
                URB_GS_PI_Current.URB_P1_Turn[Board_Number]=temptemp[2];
                URB_GS_PI_Current.URB_P2_Turn[Board_Number]=temptemp[3];
                URB_GS_PI_Current.URB_SP_Borders[Board_Number]=temptemp[6];
                URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=temptemp[7];
                URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=temptemp[0];
                URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=temptemp[1];
            }
            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
            Print_Current_Game_Status(Current_Game);
            int U_C_I=0;int R_C_I=0;
            char PVC_Beginner_Player_A_Name[100];
            printf(CYAN "Please Enter Player A Name (FIRST NAME ONLY): " RESET);scanf("%s",PVC_Beginner_Player_A_Name);
        // --------------------------------- PvC_Beginner_Mode_Start ------------------------------------------
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
                    printf(RED "Player A's Turn\n");
                    if(Current_Game.Remaining_Borders<12)
                    {
                        printf("For UNDO Type \"U U\"\nFor REDO Type \"R R\"\nTo Exit the Game Type \"E E\"\n");
                    }
                    printf("Enter The Index in the form X(Row) Y(Column): " RESET);start=time(NULL);scanf(" %s %s",&g,&f);end=time(NULL); // Scanning the index
                    // $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 
                    g[0] = (int)g[0] - 48; 
                    f[0] = (int)f[0] - 48; 
                    while(g[0] > 9 && (g[0]!=37 && g[0]!=34 && g[0]!=21) || g[0] < 0 || (int) g[1] >= 33 && (int) g[1] <= 127 || f[0] > 9 && (f[0]!=37 && f[0]!=34 && f[0]!=21) || f[0] <0 || (int) f[1] >= 33 && (int) f[1] <= 127)
                    {
                        printf(CYAN "Error, Non-Available input was given, Please check that the input is with in the Board limits X[0-5] Y[0-5]\n");
                        printf(RED "Player A's Turn\n");
                        if(Current_Game.Remaining_Borders<12)
                        {
                            printf("For UNDO Type \"U U\"\nFor REDO Type \"R R\"\nTo Exit the Game Type \"E E\"\n");
                        }
                        printf("Enter The Index in the form X(Row) Y(Column): " RESET);
                        start=time(NULL);scanf(" %s %s",&g,&f);end=time(NULL);
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
                                    Available_REDOs=0;
                                    U_C_I=0;R_C_I=0;
                                    printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                    Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                    Beginner_Board[x][y]=186;
                                    Beginner_Board_Colour[x][y]=1;
                                    Player_1.Borders++;Current_Game.First_Player_Borders++;
                                    Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp,Beginner_Board_Colour); // Checking For Created Boxes
                                    Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                    if (Player_1.Turn==0){Player_2.Turn=1;} // Giving the turn access to Player B
                                    // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                    Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                                    Current_Game.Remaining_Boxes-=temp[0];
                                    Board_Number++;
                                    Availabe_UNDOs++;
                                    Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                                    Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                                    // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                                    // FROM HERE
                                    URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                                    URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                                    URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                                    URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                                    URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                                    URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                                    URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                                    URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                                    // TO HERE
                                    system("cls");
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
                                Available_REDOs=0;
                                U_C_I=0;R_C_I=0;
                                printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                                Borders--;Current_Game.Remaining_Borders--; // Subtracting One From the Remaining Borders
                                Beginner_Board[x][y]='=';
                                Beginner_Board_Colour[x][y]=1;
                                Player_1.Borders++;Current_Game.First_Player_Borders++;
                                Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'A',temp,Beginner_Board_Colour); // Checking For Created Boxes
                                Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                if (Player_1.Turn==0){Player_2.Turn=1;} // Giving the turn access to Player B
                                // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                                Player_1.Boxes+=temp[0];Current_Game.First_Player_Boxes+=temp[0]; // Adding created boxes
                                Current_Game.Remaining_Boxes-=temp[0];
                                Board_Number++;
                                Availabe_UNDOs++;
                                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                                Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                                // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                                // FROM HERE
                                URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                                URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                                URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                                URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                                URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                                URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                                URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                                URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                                // TO HERE
                                system("cls");
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
                    else if(x==34 && y==34)
                    {
                        if(Available_REDOs>0)
                        {
                            R_C_I=1;U_C_I=0;
                            Borders--;
                            Board_Number++;
                            Availabe_UNDOs++;
                            Available_REDOs--;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                        }
                        else
                        {
                            printf(CYAN"ERROR: No Available Move can be REdone.\n"RESET);
                        }
                    }
                    else if(x==37 && y==37)
                    {
                        if(Availabe_UNDOs>0)
                        {
                            U_C_I=1;R_C_I=0;
                            Borders++;
                            Board_Number--;
                            Availabe_UNDOs--;
                            Available_REDOs++;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be undone.\n"RESET);
                        }
                    }
                    else if(x==21 && y==21)
                    {
                        system("cls");
                        printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                        char w[2];
                        scanf("%s",&w);
                        w[0]=(int)w[0]-48;
                        while(w[0] != 1 && w[0] != 2 || (int) w[1] >= 33 && (int) w[1] <= 127)
                        {
                            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
                            printf(CYAN "Type in the choice number:\n1]Save and Exit\n2]Exit without Saving\nChoice:" RESET );
                            scanf("%s",&w); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                            w[0] = (int)w[0] - 48;
                        }
                        if (w[0]==1)
                        {
                            printf(CYAN"Choose one of the following files to save your game data in.\n"
                                    "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:"RESET);
                            char ww[2];
                            scanf("%s",&ww);
                            ww[0]=(int)ww[0]-48;
                            while(ww[0] != 1 && ww[0] != 2 && ww[0] != 3 || (int) ww[1] >= 33 && (int) ww[1] <= 127)
                            {
                                printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                                printf(CYAN "1] PvP_B_G1\n2] PvP_B_G2\n3] PvP_B_G3\nChoice:" RESET );
                                scanf("%s",&ww); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                                // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                                ww[0] = (int)ww[0] - 48;
                            }
                            int temptemp[9]={Current_Game.Remaining_Borders,Current_Game.Remaining_Boxes,
                                            Player_1.Turn,Player_2.Turn,
                                            Player_1.Borders,Player_1.Boxes,
                                            Player_2.Borders,Player_2.Boxes,Board_Number};
                            Export_Data_Beginner(Beginner_Board,Beginner_Board_Colour,ww[0],temptemp);
                            printf(CYAN "DATA SAVED\n" RESET );exit(0);
                        }
                        else 
                        {
                            printf(CYAN"Data not saved.\n"RESET);exit(0);
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
                    if(U_C_I==0 && R_C_I==0)
                    {
                        int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
                        Computer_Play(6,6,4,Beginner_Board,Beginner_Board_Colour);
                        Borders--;Current_Game.Remaining_Borders--;
                        Player_2.Borders++;Current_Game.Second_Player_Borders++;
                        Check_For_Boxes_and_RE_Play(6,6,Beginner_Board,'B',temp,Beginner_Board_Colour);
                        Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                        if(Player_2.Turn==0){Player_1.Turn=1;}
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                        Player_2.Boxes+=temp[0];Current_Game.Second_Player_Boxes+=temp[0];
                        Current_Game.Remaining_Boxes-=temp[0];
                        Board_Number++;
                        Availabe_UNDOs++;
                        Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board,Beginner_Board_3D);
                        Copy_2D_To_3D(6,6,13,Board_Number,Beginner_Board_Colour,Beginner_Board_Colour_3D);
                        // Update_URB_GS_PI(&URB_GS_PI_Current,&Current_Game,&Player_1,&Player_2);
                        // From Here
                        URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
                        URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
                        URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
                        URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
                        URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
                        URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
                        URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
                        URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
                        // To Here
                        system("cls");
                        Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                        Print_Current_Game_Status(Current_Game);
                        printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                    }
                    else if (U_C_I==1)
                    {
                        if(Availabe_UNDOs>0)
                        {
                            Borders++;
                            Board_Number--;
                            Availabe_UNDOs--;
                            Available_REDOs++;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            while (Player_2.Turn==1)
                            {
                                Borders++;
                                Board_Number--;
                                Availabe_UNDOs--;
                                Available_REDOs++;
                                Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                                Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                                Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                                Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                                Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                                Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                                Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                                Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                                Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                                Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                                Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                                Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                                Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                                Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                                system("cls");
                                Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                Print_Current_Game_Status(Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            }
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be undone.\n" RESET);
                        }
                    }
                    if(R_C_I==1)
                    {
                        if(Available_REDOs>0)
                        {
                            Borders--;
                            Board_Number++;
                            Availabe_UNDOs++;
                            Available_REDOs--;
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                            Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                            Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                            Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                            Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                            Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                            Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                            Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                            Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                            Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                            system("cls");
                            Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                            Print_Current_Game_Status(Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            while (Player_2.Turn==1)
                            {
                                Borders--;
                                Board_Number++;
                                Availabe_UNDOs++;
                                Available_REDOs--;
                                Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
                                Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
                                Current_Game.Remaining_Borders=URB_GS_PI_Current.URB_Remaining_Borders[Board_Number];
                                Current_Game.Remaining_Boxes=URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number];
                                Current_Game.First_Player_Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                                Current_Game.First_Player_Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                                Current_Game.Second_Player_Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                                Current_Game.Second_Player_Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                                Player_1.Turn=URB_GS_PI_Current.URB_P1_Turn[Board_Number];
                                Player_2.Turn=URB_GS_PI_Current.URB_P2_Turn[Board_Number];
                                Player_1.Borders=URB_GS_PI_Current.URB_FP_Borders[Board_Number];
                                Player_1.Boxes=URB_GS_PI_Current.URB_FP_Boxes[Board_Number];
                                Player_2.Borders=URB_GS_PI_Current.URB_SP_Borders[Board_Number];
                                Player_2.Boxes=URB_GS_PI_Current.URB_SP_Boxes[Board_Number];
                                system("cls");
                                Print_Current_Board(6,6,Beginner_Board,Beginner_Board_Colour);
                                Print_Current_Game_Status(Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            }
                        }
                    }
                }
            }
            Print_Who_Won(Current_Game);
            Import_Beginner_Top_10_List();
            Append_New_User_And_Arrange(PVC_Beginner_Player_A_Name,Player_1.Boxes);
            Export_Beginner_Top_10_List();
            printf(CYAN"Score Has Been updated for the player !!\nCheck it from the $ Main Menu > Top 10 List $ \n"RESET);
        }
        // --------------------------------- PvC_Beginner_Mode_End ------------------------------------------
        if(o[0]==2)
        // --------------------------------- PvC_Advanced_Mode_Start ----------------------------------------
        {
            char yy[2];
            printf(CYAN "PvP_Advanced_Mode Has been chosen.\n1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy);
            yy[0] = (int)yy[0] - 48;
            while(yy[0] != 1 && yy[0] != 2 || (int) yy[1] >= 33 && (int) yy[1] <= 127)
            {
            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
            printf(CYAN "1] New Game\n2] Load an Existing Game.\nEnter: " RESET);
            scanf(" %s",&yy); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
            yy[0] = (int)yy[0] - 48;
            }
            system("cls");
            int Advanced_Board[12][12]={{}}; // Initializing 6x6 Array
            A_Initialize_PvP_Advamced_Board(12,12,Advanced_Board);
            int Advanced_Board_Colour[12][12]={{}};
            Intialize_PvP_Advanced_Board_Colour(12,12,Advanced_Board_Colour);
            A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
            A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
            int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
            int A_Borders = 60; // Game Should End after all available A_Borders are placed.
            printf("\t\t\t\t\t""\x1b[32m""Welcome to \"Dots & Boxes Game\" Advanced Mode\n""\x1b[0m"); // Welcome Statement in green
            if(yy[0]==2)
            {
                printf(CYAN"Choose one of the following files to load your game data from.\n"
                                    "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:"RESET);
                char www[2];
                scanf("%s",&www);
                www[0]=(int)www[0]-48;
                while(www[0] != 1 && www[0] != 2 && www[0] != 3 || (int) www[1] >= 33 && (int) www[1] <= 127)
                {
                    printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                    printf(CYAN "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:" RESET );
                    scanf("%s",&www); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                    // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                    www[0] = (int)www[0] - 48;
                }
                int temptemp[9];
                Import_Data_Advanced(Advanced_Board,Advanced_Board_Colour,www[0],temptemp);
                A_Current_Game.A_First_Player_Borders=temptemp[4];
                A_Current_Game.A_First_Player_Boxes=temptemp[5];
                A_Current_Game.A_Remaining_Borders=temptemp[0];
                A_Borders=temptemp[0];
                A_Current_Game.A_Remaining_Boxes=temptemp[1];
                A_Current_Game.A_Second_Player_Borders=temptemp[6];
                A_Current_Game.A_Second_Player_Boxes=temptemp[7];
                A_Player_1.Turn=temptemp[2];
                A_Player_2.Turn=temptemp[3];
                A_Player_1.Borders=temptemp[4];
                A_Player_1.Boxes=temptemp[5];
                A_Player_2.Borders=temptemp[6];
                A_Player_2.Boxes=temptemp[7];
                A_Board_Number=temptemp[8];
                Copy_2D_To_3D(6,6,13,Board_Number,Advanced_Board,Advanced_Board_3D);
                Copy_2D_To_3D(6,6,13,Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=temptemp[4];
                URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=temptemp[5];
                URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=temptemp[2];
                URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=temptemp[3];
                URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=temptemp[6];
                URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=temptemp[7];
                URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=temptemp[0];
                URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=temptemp[1];
            }
            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
            A_Print_A_Current_Game_Status(A_Current_Game);
            int A_U_C_I=0; int A_R_C_I=0;
            char PVC_Advanced_Player_A_Name[100];
            printf(CYAN "Please Enter Player A Name (FIRST NAME ONLY): " RESET);scanf("%s",PVC_Advanced_Player_A_Name);
            // --------------------------------- PvC_Advanced_Mode_Start ------------------------------------------
            while(A_Borders > 0)
            {
        // --------------------------------- Player_A's_Turn ------------------------------------------
            while(A_Player_1.Turn==1 && A_Borders >0) // Player 1 Turn is True
                {
                    int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
                    printf(RED "Player A's Turn\n");
                    if(A_Current_Game.A_Remaining_Borders<60)
                    {
                        printf("For UNDO Type \"20 20\"\nFor REDO Type \"30 30\"\nTo Exit the Game Type \"50 50\"\n");
                    }
                    printf("Enter The Index in the form X(Row) Y(Column): " RESET);start=time(NULL);scanf("%d %d",&x,&y);end=time(NULL); // Scanning the index
                    if(x>0 && y>0 && x<12 && y<12) 
                    {
                        if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
                        {
                            if(y%2==1) // Checking the Vertical A_Borders' Position.
                            {
                                if(Advanced_Board[x][y]==' ') // Checking the position is empty
                                {
                                    A_Available_REDOs=0;
                                    A_U_C_I=0;A_R_C_I=0;
                                    printf(CYAN "Position Available \"Vertical Dash\"\n" RESET); 
                                    A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                                    Advanced_Board[x][y]=186;
                                    Advanced_Board_Colour[x][y]=1;
                                    A_Player_1.Borders++;A_Current_Game.A_First_Player_Borders++;
                                    A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'A',temp,Advanced_Board_Colour); // Checking For Created Boxes
                                    A_Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                    if(A_Player_1.Turn==0)
                                    {
                                        A_Player_2.Turn=1;
                                    }
                                    // So player A will Replay, also A_Player_2.Turn will still have the value 1 waiting for its turn.
                                    A_Player_1.Boxes+=temp[0];A_Current_Game.A_First_Player_Boxes+=temp[0]; // Adding created boxes
                                    A_Current_Game.A_Remaining_Boxes-=temp[0];
                                    A_Board_Number++;
                                    A_Availabe_UNDOs++;
                                    A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                                    A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                                    // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                                    // From Here
                                    URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                                    URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                                    URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                                    URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                                    URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                                    URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                                    URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                                    URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                                    // To Here
                                    system("cls");
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
                                A_Available_REDOs=0;
                                A_U_C_I=0;A_R_C_I=0;
                                printf(CYAN "Position Available \"Horizontal Dash\"\n" RESET);
                                A_Borders--;A_Current_Game.A_Remaining_Borders--; // Subtracting One From the Remaining A_Borders
                                Advanced_Board[x][y]='=';
                                Advanced_Board_Colour[x][y]=1;
                                A_Player_1.Borders++;A_Current_Game.A_First_Player_Borders++;
                                A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'A',temp,Advanced_Board_Colour); // Checking For Created Boxes
                                A_Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                                if(A_Player_1.Turn==0)
                                {
                                    A_Player_2.Turn=1;
                                }
                                // So player A will Replay, also A_Player_2.Turn will still have the value 1 waiting for its turn.
                                A_Player_1.Boxes+=temp[0];A_Current_Game.A_First_Player_Boxes+=temp[0]; // Adding created boxes
                                A_Current_Game.A_Remaining_Boxes-=temp[0];
                                A_Board_Number++;
                                A_Availabe_UNDOs++;
                                A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                                A_Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                                // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                                // From Here
                                URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                                URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                                URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                                URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                                URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                                URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                                URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                                URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                                // To Here
                                system("cls");
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
                    else if(x==30 && y==30)
                    {
                        if(A_Available_REDOs>0)
                        {
                            A_R_C_I=1;A_U_C_I=0;
                            A_Borders--;
                            A_Board_Number++;
                            A_Availabe_UNDOs++;
                            A_Available_REDOs--;
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be REdone.\n"RESET);
                        }
                    }
                    else if(x==20 && y==20)
                    {
                        if(A_Availabe_UNDOs>0)
                        {
                            A_U_C_I=1;A_R_C_I=0;
                            A_Borders++;
                            A_Board_Number--;
                            A_Availabe_UNDOs--;
                            A_Available_REDOs++;
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                        }
                        else
                        {
                            printf(CYAN"ERROR: No Available Move can be undone.\n"RESET);
                        }
                    }
                    else if(x==50 && y==50)
                    {
                        system("cls");
                        printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                        char w[2];
                        scanf("%s",&w);
                        w[0]=(int)w[0]-48;
                        while(w[0] != 1 && w[0] != 2 || (int) w[1] >= 33 && (int) w[1] <= 127)
                        {
                            printf(CYAN "Error, Please Choose one of the 2 options only.\n" RESET);
                            printf(CYAN "Type in the choice number:\n1] Save and Exit\n2] Exit without Saving\nChoice:" RESET );
                            scanf("%s",&w); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                            // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                            w[0] = (int)w[0] - 48;
                        }
                        if (w[0]==1)
                        {
                            printf(CYAN"Choose one of the following files to save your game data in.\n"
                                    "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:"RESET);
                            char ww[2];
                            scanf("%s",&ww);
                            ww[0]=(int)ww[0]-48;
                            while(ww[0] != 1 && ww[0] != 2 && ww[0] != 3 || (int) ww[1] >= 33 && (int) ww[1] <= 127)
                            {
                                printf(CYAN "Error, Please Choose one of the 3 options only.\n" RESET);
                                printf(CYAN "1] PvP_A_G1\n2] PvP_A_G2\n3] PvP_A_G3\nChoice:" RESET );
                                scanf("%s",&ww); // Notice That the Space Before the %s is very important, if not placed, loop will run twice.
                                // As the compiler will assume the 'space' in the line before the scanf as the character to store in d.
                                ww[0] = (int)ww[0] - 48;
                            }
                            int temptemp[9]={A_Current_Game.A_Remaining_Borders,A_Current_Game.A_Remaining_Boxes,
                                            A_Player_1.Turn,A_Player_2.Turn,
                                            A_Player_1.Borders,A_Player_1.Boxes,
                                            A_Player_2.Borders,A_Player_2.Boxes,A_Board_Number};
                            Export_Data_Advanced(Advanced_Board,Advanced_Board_Colour,ww[0],temptemp);
                            printf(CYAN "DATA SAVED\n" RESET );exit(0);
                        }
                        else 
                        {
                            printf(CYAN"Data not saved.\n"RESET);exit(0);
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
                    if(A_U_C_I==0 && A_R_C_I==0)
                    {
                        int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
                        Computer_Play(12,12,25,Advanced_Board,Advanced_Board_Colour);
                        A_Borders--;A_Current_Game.A_Remaining_Borders--;
                        A_Player_2.Borders++;A_Current_Game.A_Second_Player_Borders++;
                        A_Check_For_Boxes_and_RE_Play(12,12,Advanced_Board,'B',temp,Advanced_Board_Colour);
                        A_Player_2.Turn = temp[1]; // If a box created temp[1] will be = 1
                        if(A_Player_2.Turn==0){A_Player_1.Turn=1;}
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                        A_Player_2.Boxes+=temp[0];A_Current_Game.A_Second_Player_Boxes+=temp[0];
                        A_Current_Game.A_Remaining_Boxes-=temp[0];
                        A_Board_Number++;
                        A_Availabe_UNDOs++;
                        Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board,Advanced_Board_3D);
                        Copy_2D_To_3D(12,12,61,A_Board_Number,Advanced_Board_Colour,Advanced_Board_Colour_3D);
                        // A_Update_URB_GS_PI(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
                        // From Here
                        URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
                        URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
                        URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
                        URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
                        URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
                        URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
                        URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
                        URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
                        // To Here
                        system("cls");
                        A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                        A_Print_A_Current_Game_Status(A_Current_Game);
                        printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                    }
                    else if (A_U_C_I==1)
                    {
                        if(A_Availabe_UNDOs>0)
                        {
                            A_Borders++;
                            A_Board_Number--;
                            A_Availabe_UNDOs--;
                            A_Available_REDOs++;
                            Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            while(A_Player_2.Turn==1)
                            {
                                A_Borders++;
                                A_Board_Number--;
                                A_Availabe_UNDOs--;
                                A_Available_REDOs++;
                                Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                                Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                                A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                                A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                                A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                                A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                                A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                                A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                                A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                                A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                                A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                                A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                                A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                                A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                                system("cls");
                                A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                                A_Print_A_Current_Game_Status(A_Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            }
                        }
                        else
                        {
                            printf(CYAN "ERROR: No Available Move can be undone.\n" RESET);
                        }
                    }
                    if(A_R_C_I==1)
                    {
                        if(A_Available_REDOs>0)
                        {
                            A_Borders--;
                            A_Board_Number++;
                            A_Availabe_UNDOs++;
                            A_Available_REDOs--;
                            Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                            Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                            A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                            A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                            A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                            A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                            A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                            A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                            A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                            A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                            system("cls");
                            A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                            A_Print_A_Current_Game_Status(A_Current_Game);
                            printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            while (A_Player_2.Turn==1)
                            {
                                A_Borders--;
                                A_Board_Number++;
                                A_Availabe_UNDOs++;
                                A_Available_REDOs--;
                                Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
                                Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
                                A_Current_Game.A_Remaining_Borders=URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number];
                                A_Current_Game.A_Remaining_Boxes=URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number];
                                A_Current_Game.A_First_Player_Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                                A_Current_Game.A_First_Player_Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                                A_Current_Game.A_Second_Player_Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                                A_Current_Game.A_Second_Player_Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                                A_Player_1.Turn=URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number];
                                A_Player_2.Turn=URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number];
                                A_Player_1.Borders=URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number];
                                A_Player_1.Boxes=URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number];
                                A_Player_2.Borders=URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number];
                                A_Player_2.Boxes=URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number];
                                system("cls");
                                A_Print_Current_Board(12,12,Advanced_Board,Advanced_Board_Colour);
                                A_Print_A_Current_Game_Status(A_Current_Game);
                                printf(CYAN "Time Taken By the Last User to play: %.2f Seconds\n"RESET,difftime(end,start));
                            }
                        }
                    }
                }
            }
            A_Print_Who_Won(A_Current_Game);
            Import_Advanced_Top_10_List();
            A_Append_New_User_And_Arrange(PVC_Advanced_Player_A_Name,Player_1.Boxes);
            Export_Advanced_Top_10_List();
            printf(CYAN"Score Has Been updated for the player !!\nCheck it from the $ Main Menu > Top 10 List $ \n"RESET);
        }
        // --------------------------------- PvC_Advanced_Mode_End ----------------------------------------
    }
        // ---------------------------------    PvC_Mode_End    ----------------------------------------------
    if (o[0]==3)
    {
        system("cls");
        printf(CYAN "Top 10 List Option Has Been Chosen.\n"RESET);
        printf(CYAN "Please Type The Choice Number of The Mode you want to check its related Top 10 List.\n"RESET);
        printf(CYAN "-------------------------------------------------------------------------\n" RESET);
        printf(CYAN "1] Beginner Mode Top 10 List\n2] Advanced Mode Top 10 List\nChoice Number: " RESET);
        char p[2];
        scanf(" %s",&p);
        p[0]=p[0]-48;
        while(p[0] != 1 && p[0] != 2 || (int) p[1] >= 33 && (int) p[1] <= 127) // Checking that the user has entered only 1 Digit / Character.
        {
            system("cls");
            printf(CYAN "Error, Please Choose one of the 2 options only.\n");
            printf(CYAN "1] Beginner Mode Top 10 List\n2] Advanced Mode Top 10 List\nChoice Number: " RESET);
            scanf(" %s",&p);
            p[0]=p[0]-48;
        }
        if(p[0]==1)
        {
            system("cls");
            Import_Beginner_Top_10_List();
            printf(CYAN"Name - Score\n"
                "------------\n");
            Print_Top_10_List(Names,Scores);
            printf(RESET);
        }
        if(p[0]==2)
        {
            system("cls");
            Import_Advanced_Top_10_List();
            printf(CYAN "Name - Score\n"
                "------------\n");
            Print_Top_10_List(A_Names,A_Scores);
            printf(RESET);
        }
    }
    return 0;
}