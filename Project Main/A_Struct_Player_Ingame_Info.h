/*
Module Description:
Defining Structure to hold the player ingame info
Members:
Player's Turn, Player's Borders, Player's Boxes.
*/

#ifndef A_STRUCT_PLAYER_INGAME_INFO_H
#define A_STRUCT_PLAYER_INGAME_INFO_H

// Initializing Players Ingame Info Structure
// Members:
// Turn , Borders , Boxes
struct A_Player_Ingame_Info
{
    int Turn;
    int Borders;
    int Boxes;
};
struct A_Player_Ingame_Info A_Player_1={1,0,0}; // Turn of Player_1 = 1 , Borders = 0 , Boxes = 0
struct A_Player_Ingame_Info A_Player_2={0,0,0}; // Turn of Player_2 = 0 , Borders = 0 , Boxes = 0

#endif