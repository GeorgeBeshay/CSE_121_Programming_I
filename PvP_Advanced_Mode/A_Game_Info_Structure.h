/*
Module Description:
Defining A_Game_Info_Structure
Members:
Remaining Borders, Remaining Boxes, First Player (A) Borders & Boxes, Second Player (B) Borders & Boxes, Game Status (who won)
*/

#ifndef A_GAME_INFO_STRUCTURE_H
#define A_GAME_INFO_STRUCTURE_H

// Creating Structure For each game players' Borders & Boxes 
// Members:
// 1] Remaining Borders , 2] Remaining Boxes , 3] First Player Borders , 4] First Player Boxes , 
// 5] Second Player Borders , 6] Second Player Boxes , 7] Game Status

struct A_Game_Info
{
    int A_Remaining_Borders;
    int A_Remaining_Boxes;
    int A_First_Player_Borders;
    int A_First_Player_Boxes;
    int A_Second_Player_Borders;
    int A_Second_Player_Boxes;
};
struct A_Game_Info A_Current_Game = {60,25,0,0,0,0};

#endif