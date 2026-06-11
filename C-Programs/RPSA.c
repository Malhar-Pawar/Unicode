#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Structure definition
struct RPSA{
    int MOPT;
    char MName[9];
};

int rand_no(void)   //random move selection
{
    int R;
    R = (rand()%5)+1;
    return R;
}

void GI(void)   //Game Introduction
{
    printf("\t\t\t\t\t-----Rock Paper Scissor Advanced-----\n\n");
    printf("Gameplay\n\tYou will be Competing Against Mr.Brock (The RPSA Expert).\n\tTo select any Given Option, Input the Number in front of It\n\tMr.Brock will guide you through the rest of the Game Rules.\n\n");
    printf("Mr.Brock :\n\tHi, I am Brock. We will play a Simple Game known as\n'Rock Paper Scissor', but a little advanced version of it.Lets have \n a look at Who beats whom..!\n\n");
    printf("\tRock\tbeats\tScissor,Lizard\n\tPaper\tbeats\tSpock,Rock\n\tScissor\tbeats\tPaper,Lizard\n\tLizard\tbeats\tSpock,Paper\n\tSpock\tbeats\tRock,Scissor\n\n");
}

int GMS(void)   //Game Mode Selection
{
    int gms;
    while(1)
    {
        printf("If You're Ready, Please select the Game Mode You Prefer\n1.\tSingle-Shoot\n2.\tMulti-Shoot\n\n");
        scanf(" %d", &gms);
        if(gms<1 || gms>2)
        {
            printf("Invalid Selection, Please Try Again.\n\n");
            continue;
        }
        else break;
    }
    return gms;
}
int cmpw(int c1, int p1)    //Win,Lose or Tie
{
    if(p1==1)   //Player Choose Rock
    {
        if(c1==1)
        {
            printf("Its a Tie...\n");
            return 0;
        }
        if(c1==3 || c1==4)
        {
            printf("Congratulations! You Win..!\n");
            return 1;
        }
        if(c1==2 || c1==5)
        {
            printf("You lose..\n");
            return 2;
        }
    }
    if(p1==2)   //Player Choose Paper
    {
        if(c1==2)
        {
            printf("Its a Tie...\n");
            return 0;
        }
        if(c1==1 || c1==5)
        {
            printf("Congratulations! You Win..!\n");
            return 1;
        }
        if(c1==3 || c1==4)
        {
            printf("You lose..\n");
            return 2;
        }
    }
    if(p1==3)   //Player Choose Scissor
    {
        if(c1==3)
        {
            printf("Its a Tie...\n");
            return 0;
        }
        if(c1==2 || c1==4)
        {
            printf("Congratulations! You Win..!\n");
            return 1;
        }
        if(c1==1 || c1==5)
        {
            printf("You lose..\n");
            return 2;
        }
    }
    if(p1==4)   //Player Choose Lizard
    {
        if(c1==4)
        {
            printf("Its a Tie...\n");
            return 0;
        }
        if(c1==2 || c1==5)
        {
            printf("Congratulations! You Win..!\n");
            return 1;
        }
        if(c1==1 || c1==3)
        {
            printf("You lose..\n");
            return 2;
        }
    }
    if(p1==5)   //Player Choose Spock
    {
        if(c1==5)
        {
            printf("Its a Tie...\n");
            return 0;
        }
        if(c1==1 || c1==3)
        {
            printf("Congratulations! You Win..!\n");
            return 1;
        }
        if(c1==2 || c1==4)
        {
            printf("You lose..\n");
            return 2;
        }
    }
    // return 0-tie, 1-win, 2-lose;
}
int SS(struct RPSA *pt)    //GM Single Shoot
{
    while(1)
    {
        int MB,PLR;
        MB = rand_no();
        printf("\t\tGame Start\nPlease Choose one of the Following\n1.\tRock\n2.\tPaper\n3.\tScissor\n4.\tLizard\n5.\tSpock\n\n");
        scanf(" %d", &PLR);
        if(PLR<1 || PLR>5)
        {
            printf("Invalid Selection, Please Try Again.\n\n");
            continue;
        }
        cmpw(MB, PLR);
        printf("Player:\t\t%s\nMr.Brock:\t%s\n",pt[PLR-1].MName,pt[MB-1].MName);
        break;
    }
}
int MS(struct RPSA *pt)    //GM Multi Shoot
{
    int MB,PLR,NGame,Win=0,Winc;
    printf("Enter the Number of Game You want to Play:\t");
    scanf(" %d", &NGame);
    NGame = abs(NGame);
    for(int i=0;i<NGame;i++)
    {
        MB = rand_no();
        printf("\n\t\tGame Start\nPlease Choose one of the Following\n1.\tRock\n2.\tPaper\n3.\tScissor\n4.\tLizard\n5.\tSpock\n\n");
        scanf(" %d", &PLR);
        if(PLR<1 || PLR>5)
        {
            printf("Invalid Selection, Please Try Again.\n\n");
            i--;
            continue;
        }
        Winc = cmpw(MB, PLR);
        if(Winc ==  1) Win++;
        printf("Player:\t\t%s\nMr.Brock:\t%s\n",pt[PLR-1].MName,pt[MB-1].MName);
    }
    printf("\n\nStatistics:\nYou Won %d times out of %d\n", Win,NGame);
}

int main() 
{
    //Initializations
    srand(time(0));
    int GM;
    
    //Structure
    struct RPSA RPS[5] = {
    {1, "Rock"},
    {2, "Paper"},
    {3, "Scissor"},
    {4, "Lizard"},
    {5, "Spock"}
    }; 
    struct RPSA *ptr;
    ptr = &RPS[0];
    
    //Game Intro
    GI();
    
    //Gamemode Selection
    GM = GMS();
    if(GM==1)   //Single Shoot
    {
        SS(ptr);
    }
    if(GM==2)   //Multi Shoot
    {
        MS(ptr);
    }
    return 0;
}
