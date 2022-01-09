/*
Module Description:
Defining Game_Info Structure/
Members:
Remaining Borders, Remaining Boxes, First Player (A) Borders & Boxes, Second Player (B) Borders & Boxes, Game Status (who won)
*/

#ifndef GAME_INFO_STRUCTURE_H
#define GAME_INFO_STRUCTURE_H

// Creating Structure For each game players' Borders & Boxes 
// Members:
// 1] Remaining Borders , 2] Remaining Boxes , 3] First Player Borders , 4] First Player Boxes , 
// 5] Second Player Borders , 6] Second Player Boxes , 7] Game Status
struct Game_Info
{
    int Remaining_Borders;
    int Remaining_Boxes;
    int First_Player_Borders;
    int First_Player_Boxes;
    int Second_Player_Borders;
    int Second_Player_Boxes;
};
struct Game_Info Current_Game = {12,4,0,0,0,0};

#endif