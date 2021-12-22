#include <stdio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define WHITE   "\x1b[37m"


/*
Functions ProtoType
*/

void Print_Current_Board(int x,int y,int Beginner_Board[x][y]);
void Check_For_Boxes_and_RE_Play(int x,int y,int Beginner_Board[][y],char player,int temp[2]);

int main()
{
    int Beginner_Board[12][12]={{}}; // Initializing 6x6 Array
    for(int i=0 ; i<12 ; i++)
    {
        for(int j=0 ; j<12 ; j++)
        {
            if(i==0 && j==0)
            {
                Beginner_Board[i][j]=' '; // First element TOP LEFT is Empty(Space) 
            }
            else if(i==0 || j==0)
            {
                if(i == 0)
                {
                    Beginner_Board[i][j]=j; // If Any Element in first row should show the column number which is j
                }
                if(j == 0)
                {
                    Beginner_Board[i][j]=i; // If Any Element in first Column should show the row number which is i
                }
            }
            else if(i%2!=0 && j%2!=0)
            {
                Beginner_Board[i][j]=254; // White block(dot)
            }
            else
            {
                Beginner_Board[i][j]=' '; // Initializing these places Empty, will be filled with dashes
            }
        }
    }
    int x,y; // Row , Column variables. Users will enter the position to place the border in them. 
    int Borders = 60; // Game Should End after all available borders are placed.
    int P1T=1,P2T=0; // Initializing Player 1 & 2 Turn Variables. 1 = True , 0 = False
    // Initializing Players Ingame Info Structure
    // Members:
    // Turn , Borders , Boxes
    struct Player_Ingame_Info
    {
        int Turn;
        int Borders;
        int Boxes;
    };
    struct Player_Ingame_Info Player_1={1,0,0}; // Turn of Player_1 = 1 , Borders = 0 , Boxes = 0
    struct Player_Ingame_Info Player_2={0,0,0}; // Turn of Player_2 = 0 , Borders = 0 , Boxes = 0
    Print_Current_Board(12,12,Beginner_Board);
    while(Borders > 0)
    {
        while(Player_1.Turn==1 && Borders >0) // Player 1 Turn is True
        {
            int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
            printf("Player A's Turn\nEnter The Index in the form X(Row) Y(Column): ");scanf("%d %d",&x,&y); // Scanning the index
            if(x>0 && y>0 && x<12 && y<12) 
        {
            if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
            {
                if(y%2==1) // Checking the Vertical Borders' Position.
                {
                    if(Beginner_Board[x][y]==' ') // Checking the position is empty
                    {
                        printf("Position Available \"Vertical Dash\"\n"); 
                        Borders--; // Subtracting One From the Remaining Borders
                        Beginner_Board[x][y]='|';
                        Player_2.Turn=1; // Giving the turn access to Player B
                        Player_1.Borders++;
                        Check_For_Boxes_and_RE_Play(12,12,Beginner_Board,'A',temp); // Checking For Created Boxes
                        Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                        Player_1.Boxes+=temp[0]; // Adding created boxes
                        Print_Current_Board(12,12,Beginner_Board);
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
                    Borders--; // Subtracting One From the Remaining Borders
                    Beginner_Board[x][y]='-';
                    Player_2.Turn=1; // Giving the turn access to Player B
                    Player_1.Borders++;
                    Check_For_Boxes_and_RE_Play(12,12,Beginner_Board,'A',temp); // Checking For Created Boxes
                    Player_1.Turn = temp[1]; // If a box created temp[1] will be = 1
                        // So player A will Replay, also Player_2.Turn will still have the value 1 waiting for its turn.
                    Player_1.Boxes+=temp[0]; // Adding created boxes
                    Print_Current_Board(12,12,Beginner_Board);
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
        else printf("Wrong Position, Please Try again.\n");
    }
// ------------------------------------------------------------------------------------------------
        while(Player_2.Turn==1 && Borders >0) // Player 1 Turn is True
        {
            int temp[2]={0,0}; // 1st -> Turn , 2nd -> Boxes
            printf("Player B's Turn\nEnter The Index in the form X(Row) Y(Column): ");scanf("%d %d",&x,&y); // Scanning the index
            if(x>0 && y>0 && x<12 && y<12) 
        {
            if(x%2==0) // Checking Whether the chosen Position can be placed in it a border or not 
            {
                if(y%2==1) // Checking the Vertical Borders' Position.
                {
                    if(Beginner_Board[x][y]==' ') // Checking the position is empty
                    {
                        printf("Position Available \"Vertical Dash\"\n"); 
                        Borders--; // Subtracting One From the Remaining Borders
                        Beginner_Board[x][y]='|';
                        Player_2.Borders++;
                        Player_1.Turn=1;
                        Check_For_Boxes_and_RE_Play(12,12,Beginner_Board,'B',temp);
                        Player_2.Turn = temp[1];
                        Player_2.Boxes+=temp[0];
                        Print_Current_Board(12,12,Beginner_Board);
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
                    Borders--; // Subtracting One From the Remaining Borders
                    Beginner_Board[x][y]='-';
                    Player_2.Borders++;
                    Player_1.Turn=1;
                    Check_For_Boxes_and_RE_Play(12,12,Beginner_Board,'B',temp);
                    Player_2.Turn = temp[1];
                    Player_2.Boxes+=temp[0];
                    Print_Current_Board(12,12,Beginner_Board);
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
        else printf("Wrong Position, Please Try again.\n");
        }
    }
    return 0;
}

/*
----------------------- Functions Definiton -----------------------
*/

// Function To Print The Current Board View, Will the chosen / remaining borders & boxes.

void Print_Current_Board(int x,int y,int Beginner_Board[][y])
{
for(int i=0 ; i<12 ; i++)
    {
        for(int j=0 ; j<12 ; j++)
        {
            if(i==0 && j==0)
            {
                printf("%c ",Beginner_Board[i][j]);
            }
            else if(i==0 || j==0)
            {
                printf("%d ",Beginner_Board[i][j]);
            }
            else if(i%2!=0 && j%2!=0)
            {
                printf("%c ",Beginner_Board[i][j]);
            }
            else
            {
                printf("%c ",Beginner_Board[i][j]);
            }
        }
        printf("\n");
    }
}

void Check_For_Boxes_and_RE_Play(int x,int y,int Beginner_Board[][y],char player,int temp[2])
{
    int RE_Play=0;
    int Boxes_Created=0;
    for(int i=0 ; i<25 ; i++) // 25 boxes to check, then 25 loops
    {
        for(int j=2 ; j<11 ; j*=2) // j = [2,4,6,8,10]
        {
            for(int k=2 ; k<11 ; k*=2) // k = [2,4,6,8,10]
            {
                if(Beginner_Board[j][k]==' ') // Checking if the center of the box is empty or not
                {
                    int counter=0; // Borders counter 
                    if(Beginner_Board[j-1][k]!=' '){counter++;} // Checking each border surrounding the center of the box
                    if(Beginner_Board[j+1][k]!=' '){counter++;}
                    if(Beginner_Board[j][k-1]!=' '){counter++;}
                    if(Beginner_Board[j][k+1]!=' '){counter++;}
                    if(counter == 4) // if 4 borders are counted
                    {
                        Beginner_Board[j][k]=player; // Then place the letter of the player in the center of the box
                        temp[0]=1; // Box created, then RE_Play
                        temp[1]++; // Box created, add it
                    }
                }
            }
            
        } 
    }
}