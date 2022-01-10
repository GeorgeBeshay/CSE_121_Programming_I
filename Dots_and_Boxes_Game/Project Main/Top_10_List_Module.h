#ifndef TOP_10_LIST_MODULE_H
#define TOP_10_LIST_MODULE_H

/*
- Module Description:

Defining 4 Global Variables Needed to Show the Top 10 List:
$ For Beginner
Var 1 -> Names
Var 2 -> Their Scores
$ For Advanced
Var 3 -> Names
Var 4 -> Their Scores

Defining 7 Functions Needed in the Top_10_List Editing Process:
$ For Beginner
F1 -> Importing / Arguments()
F2 -> Exporting / Arguments()
F3 -> Printing  / Arguments(Names,Scores) "Will Be Printed Descendingly"
F4 -> Arrange   / Arguments(Names,Scores)
F5 -> Append New User & Arrange / Arguments(new user name,score)
F6 -> Check To Save New User / Arguments(new user name,score) / Needed in F5
F7 -> Same String Or Not / Arguments(String1,String2) /  Needed in F6
$ For Advanced
F8 -> Importing / Arguments()
F9 -> Exporting / Arguments()
F10 -> Printing  / Arguments(Names,Scores) "Will Be Printed Descendingly"
F11 -> Arrange   / Arguments(Names,Scores)
F12 -> Append New User & Arrange / Arguments(new user name,score)
F13 -> Check To Save New User / Arguments(new user name,score) / Needed in F5
F14 -> Same String Or Not / Arguments(String1,String2) /  Needed in F6

*/

#include <stdio.h>
#include <string.h>

// Global Variables

// $$$ Beginner $$$
char Names[10][100];
int Scores[10];
// $$$ Advanced $$$
char A_Names[10][100];
int A_Scores[10];

// --------------------------

// Functions ProtoTypes 

// $$$ Beginner $$$
void Import_Beginner_Top_10_List();
void Export_Beginner_Top_10_List();
void Print_Top_10_List(char Names[10][100],int Scores[10]);
void Arrange_Ascendingly(char Names[10][100],int Scores[10]);
void Append_New_User_And_Arrange(char name[],int score);
int Check_To_Save_New_User(char name[],int score);
int Same_Or_Different(char name1[],char name2[]);
// $$$ Advanced $$$
void Import_Advanced_Top_10_List();
void Export_Advanced_Top_10_List();
void A_Print_Top_10_List(char A_Names[10][100],int A_Scores[10]);
void A_Arrange_Ascendingly(char A_Names[10][100],int A_Scores[10]);
void A_Append_New_User_And_Arrange(char A_name[],int A_score);
int A_Check_To_Save_New_User(char A_name[],int A_score);
int A_Same_Or_Different(char A_name1[],char A_name2[]);
// --------------------------

// Functions Definition

// $$$ Beginner $$$
void Import_Beginner_Top_10_List()
{
    FILE *BTL_Names;
    FILE *BTL_Scores;
    BTL_Names = fopen("Beginner_Top_10_List_Names.txt","r");
    BTL_Scores = fopen("Beginner_Top_10_List_Scores.txt","r");
    for(int i=0 ; i<10 ; i++)
    {
        fgets(Names[i],100,BTL_Names);
        for(int j=0 ; j < strlen(Names[i]) ; j++)
        {
            if(Names[i][j]=='\n'){Names[i][j]='\0';}
        }
        fscanf(BTL_Scores,"%d",&Scores[i]);
    }
    fclose(BTL_Names);
    fclose(BTL_Scores);
}

void Export_Beginner_Top_10_List()
{
    FILE *BTL_Names;
    FILE *BTL_Scores;
    BTL_Names = fopen("Beginner_Top_10_List_Names.txt","w");
    BTL_Scores = fopen("Beginner_Top_10_List_Scores.txt","w");
    for(int i=0 ; i<10 ; i++)
    {
        fprintf(BTL_Names,"%s\n",Names[i]);
        fprintf(BTL_Scores,"%d\n",Scores[i]);
    }
    fclose(BTL_Names);
    fclose(BTL_Scores);
}

void Print_Top_10_List(char Names[10][100],int Scores[10])
{
    for(int i=9 ; i>=0 ; i--)
    {
	switch(i)
	{
		case 9:printf("1st: ");break;
		case 8:printf("2nd: ");break;
		case 7:printf("3rd: ");break;
		case 6:printf("4th: ");break;
		case 5:printf("5th: ");break;
		case 4:printf("6th: ");break;
		case 3:printf("7th: ");break;
		case 2:printf("8th: ");break;
		case 1:printf("9th: ");break;
		case 0:printf("10th: ");break;
	}
        printf("%s - %d\n",Names[i],Scores[i]);
    }
}

void Arrange_Ascendingly(char Names[10][100],int Scores[10]) // By Using Bubble Sorting
{
    int Sorted=-10;
    while(Sorted!=0)
    {
        for(int i=0 ; i<9 ; i++)
        {
            if(Scores[i]>Scores[i+1])
            {
                    int temps = Scores[i+1];
                    Scores[i+1]= Scores[i];
                    Scores[i]= temps;
                    char tempn[100];
                    strcpy(tempn,Names[i+1]);
                    strcpy(Names[i+1],Names[i]);
                    strcpy(Names[i],tempn);
            }
        }
        Sorted++;
    }
}

void Append_New_User_And_Arrange(char name[],int score) 
{
    if(Check_To_Save_New_User(name,score) == 0)
    {
        if (score > Scores[0])
        {
            Scores[0]=score;
            strcpy(Names[0],name);
            Arrange_Ascendingly(Names,Scores);
        }
        else
        {
            printf(CYAN "Sorry The User Score is not high enough to be placed in the Top 10 List.\n" RESET);
        }
    }
    else
    {
        Scores[Check_To_Save_New_User(name,score)%10]+=score;
        Arrange_Ascendingly(Names,Scores);
        printf(CYAN "The User is already in the top List, Score Has Been Updated.\n"RESET);
    }
}

int Check_To_Save_New_User(char name[],int score)
{
    int ErrorValue=0;
    int T=0;
    for(int i=0 ; i<10 ; i++)
    {
        if(Same_Or_Different(name,Names[i])==1)
        {
            ErrorValue=1;
            T = i;
        }
    }
    ErrorValue = ErrorValue*10+T;
    return ErrorValue;
}

int Same_Or_Different(char name1[],char name2[])
{
    int SameString=0;
    int c=0;
    if(strlen(name1)==strlen(name2))
    {
        for(int i=0 ; i<strlen(name1) ; i++)
        {
            if(name1[i]==name2[i])
            {
                c++;
            }
        }
    }
    if(c==strlen(name1)&&c==strlen(name2))
    {
        SameString=1;
    }
    return SameString;
}
// $$$ Advanced $$$
void Import_Advanced_Top_10_List()
{
    FILE *ATL_Names;
    FILE *ATL_Scores;
    ATL_Names = fopen("Advanced_Top_10_List_Names.txt","r");
    ATL_Scores = fopen("Advanced_Top_10_List_Scores.txt","r");
    for(int i=0 ; i<10 ; i++)
    {
        fgets(A_Names[i],100,ATL_Names);
        for(int j=0 ; j < strlen(A_Names[i]) ; j++)
        {
            if(A_Names[i][j]=='\n'){A_Names[i][j]='\0';}
        }
        fscanf(ATL_Scores,"%d",&A_Scores[i]);
    }
    fclose(ATL_Names);
    fclose(ATL_Scores);
}

void Export_Advanced_Top_10_List()
{
    FILE *ATL_Names;
    FILE *ATL_Scores;
    ATL_Names = fopen("Advanced_Top_10_List_Names.txt","w");
    ATL_Scores = fopen("Advanced_Top_10_List_Scores.txt","w");
    for(int i=0 ; i<10 ; i++)
    {
        fprintf(ATL_Names,"%s\n",A_Names[i]);
        fprintf(ATL_Scores,"%d\n",A_Scores[i]);
    }
    fclose(ATL_Names);
    fclose(ATL_Scores);
}

void A_Print_Top_10_List(char A_Names[10][100],int A_Scores[10])
{
    for(int i=9 ; i>=0 ; i--)
    {
        printf("%s - %d\n",A_Names[i],A_Scores[i]);
    }
}

void A_Arrange_Ascendingly(char A_Names[10][100],int A_Scores[10]) // By Using Bubble Sorting
{
    int A_Sorted=-10;
    while(A_Sorted!=0)
    {
        for(int i=0 ; i<9 ; i++)
        {
            if(A_Scores[i]>A_Scores[i+1])
            {
                    int A_temps = A_Scores[i+1];
                    A_Scores[i+1]= A_Scores[i];
                    A_Scores[i]= A_temps;
                    char A_tempn[100];
                    strcpy(A_tempn,A_Names[i+1]);
                    strcpy(A_Names[i+1],A_Names[i]);
                    strcpy(A_Names[i],A_tempn);
            }
        }
        A_Sorted++;
    }
}

void A_Append_New_User_And_Arrange(char A_name[],int A_score) 
{
    if(A_Check_To_Save_New_User(A_name,A_score) == 0)
    {
        if (A_score > A_Scores[0])
        {
            A_Scores[0]=A_score;
            strcpy(A_Names[0],A_name);
            A_Arrange_Ascendingly(A_Names,A_Scores);
        }
        else
        {
            printf(CYAN "Sorry The User Score is not high enough to be placed in the Top 10 List.\n"RESET);
        }
    }
    else
    {
        A_Scores[Check_To_Save_New_User(A_name,A_score)%10]+=A_score;
        A_Arrange_Ascendingly(A_Names,A_Scores);
        printf("The User is already in the top List, Score Has Been Updated.\n");
    }
}

int A_Check_To_Save_New_User(char A_name[],int A_score)
{
    int A_ErrorValue=0;
    int A_T=0;
    for(int i=0 ; i<10 ; i++)
    {
        if(A_Same_Or_Different(A_name,A_Names[i])==1)
        {
            A_ErrorValue=1;
            A_T = i;
        }
    }
    A_ErrorValue = A_ErrorValue*10+A_T;
    return A_ErrorValue;
}

int A_Same_Or_Different(char A_name1[],char A_name2[])
{
    int A_SameString=0;
    int A_c=0;
    if(strlen(A_name1)==strlen(A_name2))
    {
        for(int i=0 ; i<strlen(A_name1) ; i++)
        {
            if(A_name1[i]==A_name2[i])
            {
                A_c++;
            }
        }
    }
    if(A_c==strlen(A_name1)&&A_c==strlen(A_name2))
    {
        A_SameString=1;
    }
    return A_SameString;
}
// --------------------------

#endif