#ifndef UNDO_REDO_MODULE_H
#define UNDO_REDO_MODULE_H

/*
- Module Description
*/

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

// Global Variables

// $$$ Beginner $$$
int Board_Number=0;
int Availabe_UNDOs=0;
int Available_REDOs=0;
int Beginner_Board_3D[6][6][13];
int Beginner_Board_Colour_3D[6][6][13];
// $$$ Advanced $$$
int A_Board_Number=0;
int A_Availabe_UNDOs=0;
int A_Available_REDOs=0;
int Advanced_Board_3D[12][12][61];
int Advanced_Board_Colour_3D[12][12][61];
// ---------------

// Global Structures

// $$$ Beginner $$$

int URB_GS_PI_Array[8][14]=
{
    {12},{4},{0},{0},{0},{0},{1},{0}
};

struct U_R_B_Game_Status_Player_Info
{
    int URB_Remaining_Borders[13];
    int URB_Remaining_Boxes[13];
    int URB_FP_Borders[13]; // FP -> First Player
    int URB_FP_Boxes[13];
    int URB_SP_Borders[13];
    int URB_SP_Boxes[13];
    int URB_P1_Turn[13];
    int URB_P2_Turn[13];
};
struct U_R_B_Game_Status_Player_Info URB_GS_PI_Current = {{12},{4},{0},{0},{0},{0},{1},{0}};

// $$$ Advanced $$$
struct U_R_A_Game_Status_Player_Info
{
    int URA_A_Remaining_Borders[61];
    int URA_A_Remaining_Boxes[61];
    int URA_A_FP_Borders[61]; // FP -> First Player
    int URA_A_FP_Boxes[61];
    int URA_A_SP_Borders[61];
    int URA_A_SP_Boxes[61];
    int URA_A_P1_Turn[61];
    int URA_A_P2_Turn[61];
};
struct U_R_A_Game_Status_Player_Info URA_GS_PI_Current = {{60},{25},{0},{0},{0},{0},{1},{0}};
// ---------------

// Functions ProtoType

// $$$ Beginner $$$
void Copy_2D_To_3D(int x,int y,int z,int Board_Number,int Any_2D[x][y],int Any_3D[x][y][z]);
void Copy_3D_To_2D(int x,int y,int z,int Board_Number,int Any_3D[x][y][z],int Any_2D[x][y]);
void Update_URB_GS_PI(struct U_R_B_Game_Status_Player_Info URB_GS_PI_Current,struct Game_Info Current_Game,struct Player_Ingame_Info Player_1,struct Player_Ingame_Info Player_2);
void Update_GS_PI_After_UR(struct U_R_B_Game_Status_Player_Info URB_GS_PI_Current,struct Game_Info Current_Game,struct Player_Ingame_Info Player_1,struct Player_Ingame_Info Player_2);
void Request_Undo(int Beginner_Board[6][6],int Beginner_Board_Colour[6][6],struct Game_Info Current_Game,struct Player_Ingame_Info Player_1,struct Player_Ingame_Info Player_2);
void Request_Redo(int Beginner_Board[6][6],int Beginner_Board_Colour[6][6]);
// $$$ Advanced $$$
void A_Copy_2D_To_3D(int x,int y,int z,int A_Board_Number,int Any_2D[x][y],int Any_3D[x][y][z]);
void A_Copy_3D_To_2D(int x,int y,int z,int A_Board_Number,int Any_3D[x][y][z],int Any_2D[x][y]);
void A_Update_URB_GS_PI(struct U_R_A_Game_Status_Player_Info URA_GS_PI_Current,struct A_Game_Info A_Current_Game,struct A_Player_Ingame_Info A_Player_1,struct A_Player_Ingame_Info A_Player_2);
void A_Update_GS_PI_After_UR(struct U_R_A_Game_Status_Player_Info URA_GS_PI_Current,struct A_Game_Info A_Current_Game,struct A_Player_Ingame_Info A_Player_1,struct A_Player_Ingame_Info A_Player_2);
void A_Request_Undo(int Advanced_Board[12][12],int Advanced_Board_Colour[12][12]);
void A_Request_Redo(int Advanced_Board[12][12],int Advanced_Board_Colour[12][12]);
// ---------------

// Functions Definition

// $$$ Beginner $$$
void Copy_2D_To_3D(int x,int y,int z,int Board_Number,int Any_2D[x][y],int Any_3D[x][y][z]) // Third Dimension Argument is Constant <= Max No. Representing which Parallel Board Would Be Copied
{
    for (int i=0 ; i<x ; i++)
    {
        for(int j=0 ; j<y ; j++)
        {
            Any_3D[i][j][Board_Number] = Any_2D[i][j];
        }
    }
}

void Copy_3D_To_2D(int x,int y,int z,int Board_Number,int Any_3D[x][y][z],int Any_2D[x][y]) // Third Dimension Argument is Constant <= Max No. Representing which Parallel Board Would Be Copied
{
    for (int i=0 ; i<x ; i++)
    {
        for(int j=0 ; j<y ; j++)
        {
            Any_2D[i][j] = Any_3D[i][j][Board_Number];
        }
    }
}

void Update_URB_GS_PI(struct U_R_B_Game_Status_Player_Info URB_GS_PI_Current,struct Game_Info Current_Game,struct Player_Ingame_Info Player_1,struct Player_Ingame_Info Player_2)
{
    URB_GS_PI_Current.URB_Remaining_Borders[Board_Number]=Current_Game.Remaining_Borders;
    URB_GS_PI_Current.URB_Remaining_Boxes[Board_Number]=Current_Game.Remaining_Boxes;
    URB_GS_PI_Current.URB_FP_Borders[Board_Number]=Current_Game.First_Player_Borders;
    URB_GS_PI_Current.URB_FP_Boxes[Board_Number]=Current_Game.First_Player_Boxes;
    URB_GS_PI_Current.URB_SP_Borders[Board_Number]=Current_Game.Second_Player_Borders;
    URB_GS_PI_Current.URB_SP_Boxes[Board_Number]=Current_Game.Second_Player_Boxes;
    URB_GS_PI_Current.URB_P1_Turn[Board_Number]=Player_1.Turn;
    URB_GS_PI_Current.URB_P2_Turn[Board_Number]=Player_2.Turn;
}

void Update_GS_PI_After_UR(struct U_R_B_Game_Status_Player_Info URB_GS_PI_Current,struct Game_Info Current_Game,struct Player_Ingame_Info Player_1,struct Player_Ingame_Info Player_2)
{
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
}

void Request_Undo(int Beginner_Board[6][6],int Beginner_Board_Colour[6][6],struct Game_Info Current_Game,struct Player_Ingame_Info Player_1,struct Player_Ingame_Info Player_2)
{
    if(Availabe_UNDOs>0)
    {
        Board_Number--;
        Availabe_UNDOs--;
        Available_REDOs++;
        Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
        Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
        Update_GS_PI_After_UR(URB_GS_PI_Current,Current_Game,Player_1,Player_2);
    }
    else
    {
        printf("ERROR: No Available Move can be undone.\n");
    }
}

void Request_Redo(int Beginner_Board[6][6],int Beginner_Board_Colour[6][6])
{
    if(Available_REDOs>0)
    {
        Board_Number++;
        Availabe_UNDOs++;
        Available_REDOs--;
        Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_3D,Beginner_Board);
        Copy_3D_To_2D(6,6,13,Board_Number,Beginner_Board_Colour_3D,Beginner_Board_Colour);
        Update_GS_PI_After_UR(URB_GS_PI_Current,Current_Game,Player_1,Player_2);
    }
    else
    {
        printf("ERROR: No Available Move can be REdone.\n");
    }
}

// $$$ Advanced $$$
void A_Copy_2D_To_3D(int x,int y,int z,int A_Board_Number,int Any_2D[x][y],int Any_3D[x][y][z]) // Third Dimension Argument is Constant <= Max No. Representing which Parallel Board Would Be Copied
{
    for (int i=0 ; i<x ; i++)
    {
        for(int j=0 ; j<y ; j++)
        {
            Any_3D[i][j][A_Board_Number] = Any_2D[i][j];
        }
    }
}

void A_Copy_3D_To_2D(int x,int y,int z,int A_Board_Number,int Any_3D[x][y][z],int Any_2D[x][y]) // Third Dimension Argument is Constant <= Max No. Representing which Parallel Board Would Be Copied
{
    for (int i=0 ; i<x ; i++)
    {
        for(int j=0 ; j<y ; j++)
        {
            Any_2D[i][j] = Any_3D[i][j][A_Board_Number];
        }
    }
}

void A_Update_URB_GS_PI(struct U_R_A_Game_Status_Player_Info URA_GS_PI_Current,struct A_Game_Info A_Current_Game,struct A_Player_Ingame_Info A_Player_1,struct A_Player_Ingame_Info A_Player_2)
{
    URA_GS_PI_Current.URA_A_Remaining_Borders[A_Board_Number]=A_Current_Game.A_Remaining_Borders;
    URA_GS_PI_Current.URA_A_Remaining_Boxes[A_Board_Number]=A_Current_Game.A_Remaining_Boxes;
    URA_GS_PI_Current.URA_A_FP_Borders[A_Board_Number]=A_Current_Game.A_First_Player_Borders;
    URA_GS_PI_Current.URA_A_FP_Boxes[A_Board_Number]=A_Current_Game.A_First_Player_Boxes;
    URA_GS_PI_Current.URA_A_SP_Borders[A_Board_Number]=A_Current_Game.A_Second_Player_Borders;
    URA_GS_PI_Current.URA_A_SP_Boxes[A_Board_Number]=A_Current_Game.A_Second_Player_Boxes;
    URA_GS_PI_Current.URA_A_P1_Turn[A_Board_Number]=A_Player_1.Turn;
    URA_GS_PI_Current.URA_A_P2_Turn[A_Board_Number]=A_Player_2.Turn;
}

void A_Update_GS_PI_After_UR(struct U_R_A_Game_Status_Player_Info URA_GS_PI_Current,struct A_Game_Info A_Current_Game,struct A_Player_Ingame_Info A_Player_1,struct A_Player_Ingame_Info A_Player_2)
{
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
}

void A_Request_Undo(int Advanced_Board[12][12],int Advanced_Board_Colour[12][12])
{
    if(A_Availabe_UNDOs>0)
    {
        A_Board_Number--;
        A_Availabe_UNDOs--;
        A_Available_REDOs++;
        A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
        A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
        A_Update_GS_PI_After_UR(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
    }
    else
    {
        printf("ERROR: No Available Move can be undone.\n");
    }
}

void A_Request_Redo(int Advanced_Board[12][12],int Advanced_Board_Colour[12][12])
{
    if(A_Available_REDOs>0)
    {
        A_Board_Number++;
        A_Availabe_UNDOs++;
        A_Available_REDOs--;
        A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_3D,Advanced_Board);
        A_Copy_3D_To_2D(12,12,61,A_Board_Number,Advanced_Board_Colour_3D,Advanced_Board_Colour);
        A_Update_GS_PI_After_UR(URA_GS_PI_Current,A_Current_Game,A_Player_1,A_Player_2);
    }
    else
    {
        printf("ERROR: No Available Move can be REdone.\n");
    }
}
// ---------------
#endif