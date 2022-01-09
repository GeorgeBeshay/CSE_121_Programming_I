/*
- Module Description:
= Defining Export_Data_Beginner_PvP() Function
= Exporting "Saving" The Game Data {Borders, Boxes, For Each Player}
= Arguments:
    $ Beginner_Board[6][6]
    $ Beginner_BoarD_Colour[6][6]
    $ Game_Info Structure -> Current_Game
    $ Plyaer_Ingame_Info Structure -> Player_1 , Player_2 
= >>>> Data Model <<<<
Line Number ]  Text
            FROM HERE
01          ]  00 01 02 03 04 05        This is the value of the board elements 
02          ]  10 11 12 13 14 15
03          ]  20 21 22 23 24 25
04          ]  30 31 32 33 34 35
05          ]  40 41 42 43 44 45
06          ]  50 51 52 53 54 55
            TO HERE - will be repeated 13 times
            FROM HERE
08          ]  00 01 02 03 04 05        This is the value of the board colour elements 
08          ]  10 11 12 13 14 15
09          ]  20 21 22 23 24 25
10          ]  30 31 32 33 34 35
11          ]  40 41 42 43 44 45
12          ]  50 51 52 53 54 55
            TO HERE - will be repeated 13 times
            FROM HERE
            N N N N N N N N [Borders - Boxes - FP Borders - FP Boxes - SP Borders - SP Boxes - FP turn - SP Turn]
            TO HERE - will be repeated 13 times
            BN - Board Number
*/

#ifndef EXPORT_DATA_H
#define EXPORT_DATA_H

#include <stdlib.h>
#include <stdio.h>
#include "Undo_Redo_Module.h"
FILE *fp;

void Export_Data_Beginner(int Beginner_Board[6][6],int Beginner_Board_Colour[6][6],int u,int temptemp[9])
// void Export_Data_Beginner(int Beginner_Board_3D[6][6][13],int Beginner_Board_Colour_3D[6][6][13],struct U_R_B_Game_Status_Player_Info URB_GS_PI_Current_Game,int u,int Board_Number)
{
    FILE *fp;
    switch(u)
    {
    case 1: fp = fopen("PvP_B_G1.txt","w");break;
    case 2: fp = fopen("PvP_B_G2.txt","w");break;
    case 3: fp = fopen("PvP_B_G3.txt","w");break;
    };
    // for(int k=0 ; k<13 ; k++)
    // {
        for(int i=0 ; i<6 ; i++)
        {
            for(int j=0 ; j<6 ; j++)
            {
                fprintf(fp,"%d ",Beginner_Board[i][j]);
                // fprintf(fp,"%d ",Beginner_Board_3D[i][j][k]);
            }
            fprintf(fp,"\n");
        }
    // }
    // for(int k=0 ; k<13 ; k++)
    // {
        for(int i=0 ; i<6 ; i++)
        {
            for(int j=0 ; j<6 ; j++)
            {
                fprintf(fp,"%d ",Beginner_Board_Colour[i][j]);
                // fprintf(fp,"%d ",Beginner_Board_Colour_3D[i][j][k]);
            }
            fprintf(fp,"\n");
        }
        // fprintf(fp,"%d %d");
    // }
    // for(int k=0 ; k<13 ; k++)
    // {
    //     fprintf(fp,"%d %d %d %d %d %d %d %d\n",
    //     URB_GS_PI_Current.URB_Remaining_Borders[k],
    //     URB_GS_PI_Current.URB_Remaining_Boxes[k],
    //     URB_GS_PI_Current.URB_FP_Borders[k],
    //     URB_GS_PI_Current.URB_FP_Boxes[k],
    //     URB_GS_PI_Current.URB_SP_Borders[k],
    //     URB_GS_PI_Current.URB_SP_Boxes[k],
    //     URB_GS_PI_Current.URB_P1_Turn[k],
    //     URB_GS_PI_Current.URB_P2_Turn[k]);
    // }
    // fprintf(fp,"%d\n",Board_Number);
    for(int i=0 ; i<9 ; i++)
    {
        fprintf(fp,"%d\n",temptemp[i]);
    }
    fclose(fp);
}

void Import_Data_Beginner(int Beginner_Board[6][6],int Beginner_Board_Colour[6][6],int u,int temptemp[9])
// void Import_Data_Beginner(int Beginner_Board_3D[6][6][13],int Beginner_Board_Colour_3D[6][6][13],struct U_R_B_Game_Status_Player_Info* URB_GS_PI_Current,int u,int* Board_Number)
{
    FILE *fp;
    switch(u)
    {
    case 1: fp = fopen("PvP_B_G1.txt","r");break;
    case 2: fp = fopen("PvP_B_G2.txt","r");break;
    case 3: fp = fopen("PvP_B_G3.txt","r");break;
    };
    // for(int k=0 ; k<13 ; k++)
    // {
        for(int i=0 ; i<6 ; i++)
        {
            for(int j=0 ; j<6 ; j++)
            {
                fscanf(fp,"%d ",&Beginner_Board[i][j]);
            }
        }
    // }
    // for(int k=0 ; k<13 ; k++)
    // {
        for(int i=0 ; i<6 ; i++)
        {
            for(int j=0 ; j<6 ; j++)
            {
                fscanf(fp,"%d ",&Beginner_Board_Colour[i][j]);
            }
        }
    // }
    // for(int k=0 ; k<13 ; k++)
    // {
    //     fscanf(fp,"%d %d %d %d %d %d %d %d\n",
    //     &URB_GS_PI_Current->URB_Remaining_Borders[k],
    //     &URB_GS_PI_Current->URB_Remaining_Boxes[k],
    //     &URB_GS_PI_Current->URB_FP_Borders[k],
    //     &URB_GS_PI_Current->URB_FP_Boxes[k],
    //     &URB_GS_PI_Current->URB_SP_Borders[k],
    //     &URB_GS_PI_Current->URB_SP_Boxes[k],
    //     &URB_GS_PI_Current->URB_P1_Turn[k],
    //     &URB_GS_PI_Current->URB_P2_Turn[k]);
    // }
    // fscanf(fp,"%d ",&Board_Number);
    for(int i=0 ; i<9 ; i++)
    {
        fscanf(fp,"%d\n",&temptemp[i]);
    }
    fclose(fp);
}

/*
    FILE *fp;
    switch(u)
    {
    case 1: fp = fopen("PvP_B_G1.txt","r");break;
    case 2: fp = fopen("PvP_B_G2.txt","r");break;
    case 3: fp = fopen("PvP_B_G3.txt","r");break;
    };
    for(int k=0 ; k<13 ; k++)
    {
        fscanf(fp,"%d %d %d %d %d %d %d %d\n",
        &URB_GS_PI_Current.URB_Remaining_Borders[k],
        &URB_GS_PI_Current.URB_Remaining_Boxes[k],
        &URB_GS_PI_Current.URB_FP_Borders[k],
        &URB_GS_PI_Current.URB_FP_Boxes[k],
        &URB_GS_PI_Current.URB_SP_Borders[k],
        &URB_GS_PI_Current.URB_SP_Boxes[k],
        &URB_GS_PI_Current.URB_P1_Turn[k],
        &URB_GS_PI_Current.URB_P2_Turn[k]);
    }
    fscanf(fp,"%d ",&Board_Number);

    fclose(fp);
*/

// -------------------------------------------------------------------------------------------------------

void Export_Data_Advanced(int Advanced_Board_3D[12][12][61],int Advanced_Board_Colour_3D[12][12][61],struct U_R_A_Game_Status_Player_Info URA_GS_PI_Current_Game,int u,int BN)
{
    FILE *fp;
    switch(u)
    {
    case 1: fp = fopen("PvP_A_G1.txt","w");break;
    case 2: fp = fopen("PvP_A_G2.txt","w");break;
    case 3: fp = fopen("PvP_A_G3.txt","w");break;
    };
    for(int k=0 ; k<61 ; k++)
    {
        for(int i=0 ; i<12 ; i++)
        {
            for(int j=0 ; j<12 ; j++)
            {
                fprintf(fp,"%d ",Advanced_Board_3D[i][j][k]);
            }
            fprintf(fp,"\n");
        }
    }
    for(int k=0 ; k<61 ; k++)
    {
        for(int i=0 ; i<12 ; i++)
        {
            for(int j=0 ; j<12 ; j++)
            {
                fprintf(fp,"%d ",Advanced_Board_Colour_3D[i][j][k]);
            }
            fprintf(fp,"\n");
        }
    }
    for(int k=0 ; k<61 ; k++)
    {
        fprintf(fp,"%d %d %d %d %d %d %d %d\n",
        URA_GS_PI_Current.URA_A_Remaining_Borders[k],
        URA_GS_PI_Current.URA_A_Remaining_Boxes[k],
        URA_GS_PI_Current.URA_A_FP_Borders[k],
        URA_GS_PI_Current.URA_A_FP_Boxes[k],
        URA_GS_PI_Current.URA_A_SP_Borders[k],
        URA_GS_PI_Current.URA_A_SP_Boxes[k],
        URA_GS_PI_Current.URA_A_P1_Turn[k],
        URA_GS_PI_Current.URA_A_P2_Turn[k]);
    }
    fprintf(fp,"%d\n",BN);
    fclose(fp);
}

void Import_Data_Advanced(int Advanced_Board_3D[12][12][61],int Advanced_Board_Colour_3D[12][12][61],int u)
{
    FILE *fp;
    switch(u)
    {
    case 1: fp = fopen("PvP_A_G1.txt","w");break;
    case 2: fp = fopen("PvP_A_G2.txt","w");break;
    case 3: fp = fopen("PvP_A_G3.txt","w");break;
    };
    for(int k=0 ; k<61 ; k++)
    {
        for(int i=0 ; i<12 ; i++)
        {
            for(int j=0 ; j<12 ; j++)
            {
                fscanf(fp,"%d ",&Advanced_Board_3D[i][j][k]);
            }
        }
    }
    for(int k=0 ; k<61 ; k++)
    {
        for(int i=0 ; i<12 ; i++)
        {
            for(int j=0 ; j<12 ; j++)
            {
                fscanf(fp,"%d ",&Advanced_Board_Colour_3D[i][j][k]);
            }
        }
    }
    fclose(fp);
}

/*
    FILE *fp;
    switch(u)
    {
    case 1: fp = fopen("PvP_A_G1.txt","w");break;
    case 2: fp = fopen("PvP_A_G2.txt","w");break;
    case 3: fp = fopen("PvP_A_G3.txt","w");break;
    };
    for(int k=0 ; k<61 ; k++)
    {
        fscanf(fp,"%d %d %d %d %d %d %d %d\n",
        &URA_GS_PI_Current.URA_A_Remaining_Borders[k],
        &URA_GS_PI_Current.URA_A_Remaining_Boxes[k],
        &URA_GS_PI_Current.URA_A_FP_Borders[k],
        &URA_GS_PI_Current.URA_A_FP_Boxes[k],
        &URA_GS_PI_Current.URA_A_SP_Borders[k],
        &URA_GS_PI_Current.URA_A_SP_Boxes[k],
        &URA_GS_PI_Current.URA_A_P1_Turn[k],
        &URA_GS_PI_Current.URA_A_P2_Turn[k]);
    }
    fscanf(fp,"%d ",&A_Board_Number);
    fclose(fp);
*/
#endif