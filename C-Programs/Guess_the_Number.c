#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RN(void)    //Number Picker
{
    int randno;
    randno= (rand()%100)+1;
    return randno;
}

int main() 
{
    //Intitializations
    int n,guess=1;
    srand(time(0));
    int bot=RN();
    
    
    //Game Intro
    printf("\t\t\t\t\t-----Guess the Number-----\n\n");
    printf("Gameplay:\n\tMr.Bot picks up a number between 1-100.\n\tYour Goal is to Guess the Number picked by Mr.Bot.\n\tAfter Each Guess, Mr.Bot will tell You whether you are High or Low.\n\n");
    
    printf("Mr.Bot : Hey Challenger..! Think you can beat me? Go on then..!\n");
    
    //Game Loop
    while(1)
    {
        printf("\nGuess the Number:\t");
        scanf(" %d", &n);
        if(n<1 || n>100)
        {
            printf("Mr.Bot : Please keep your number between 1 and 100.\n"); 
            continue;
        }
        if(n==bot)
        {
            break;
        }
        if(n>bot)
        {
            printf("Mr.Bot : You're High...\n");
            guess++;
        }
        if(n<bot)
        {
            printf("Mr.Bot : You're Low...\n");
            guess++;
        }
    }
    printf("\n\nGuess Taken:\t%d\n",guess);
    switch(guess)
    {
        case 1:
        {
            printf("Mr.Bot : You got a Lucky Shot...!\n"); 
            break;
        }
        case 2:
        {
            printf("Mr.Bot : You're a Champion..!\n");
            break;
        }
        case 3:
        {
            printf("Mr.Bot : Precise Guess..!\n");
            break;
        }
        case 4:
        {
            printf("Mr.Bot : A Master Strategist..!\n");
            break;
        }
        case 5:
        {
            printf("Mr.Bot : An Expert in the Game..!\n");
            break;
        }
        case 6:
        {
            printf("Mr.Bot : Had a good game..!\n");
            break;
        }
        case 7:
        {
            printf("Mr.Bot : Come prepared next time..!\n");
            break;
        }
        default: 
        {
            printf("Mr.Bot : Won the Game, but still a Loser!!\n");
            break;
        }
    }
    
    return 0;
}
