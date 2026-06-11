#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define size 10

int main() 
{
    //initializations
    int matrix[size][size];
    char hashmat[size][size];
    int i,j,a,b,x,y,n,m,o,p,d,mine=0,scr=0;
    srand(time(0));
    
    //minefield initialization
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            matrix[i][j]=0;
        }
    }
    
    //minefield setup
    while(mine < size)
    {
        x = rand() % size;
        y = rand() % size;
        if(matrix[x][y] == 0)
        {
            matrix[x][y] = 1;
            mine++;
        }
    }
    
    //Display Matrix Setup
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            hashmat[i][j]='+';
        }   
    }
    
    //Game Start
    
    //Game Info
    printf("\t\t\t-----Minefields-----\n\n");
    printf("Gameplay:\n\tDig a Hole using Co-ordinate Input ( between 0 0 and %d %d ).\n\tYou Either Hit a Diamond or a Mine.\n\tAvoid the Mines and Obtain the Diamonds.\n\tWhen you hit a Diamond, you get a hint about a Diamond or a Mine.\n\tYou lose if You hit a Mine..!!\n\n", size,size);
    
    while(1)
    {
        //Display Minefield
        printf("M\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
        for(i=0;i<size;i++)
        {
            printf("%d\t", i);
            for(j=0;j<size;j++)
            {
                printf("%c\t", hashmat[i][j]);
            }   printf("\n");
        }
        
        //User Input
        printf("\nDig a Hole...\n");
        scanf(" %d %d", &a, &b);
        
        //Input Validation
        if(a<0 || a>=size || b<0 || b>=size)
        {
            printf("\nInvalid Input: Try Again\n");
            continue;
        }
        
        //previously used Input
        if(hashmat[a][b]=='X')
        {
            printf("\nYou've already broken ground here; find a new place to dig.\n");
            continue;
        }
        
        if(hashmat[a][b]=='+')
        {
            //Gameover
            if(matrix[a][b]==1)
            {
                printf("\nGame Over\nScore = %d", scr);
                break;
            }
            //Game On
            if(matrix[a][b]==0)
            {
                //Appreciation
                hashmat[a][b]='X';
                scr++;
                printf("\nYou Found a Diamond!!\nScore = %d\n", scr);
                
                //Hints
                while(1)
                {
                    //Random non-dug square and its abs distance
                    n = rand()%size; m = rand()%size;
                    if(hashmat[n][m]=='X') continue;
                    o = abs(a-n); p = abs(b-m);
                    //decision factor
                    d = rand()%2;
                    //Distance in Rows
                    if(d==0)
                    {
                        //If Diamond
                        if(matrix[n][m]==0)
                        {
                            //If same Rows (Distance in Columns)
                            if(o==0)
                            {
                                printf("Hint: There is a Diamond at a distance of %d\n", p);
                                break;
                            }
                            //If different Rows
                            printf("Hint: There is a Diamond at a distance of %d\n", o);
                        }
                        
                        //If Mine
                        if(matrix[n][m]==1)
                        {
                            //If same Rows (Distance in Columns)
                            if(o==0)
                            {
                                printf("Beware! There is a Mine at a distance of %d\n", p);
                                break;
                            }
                            //If different Rows
                            printf("Beware! There is a Mine at a distance of %d\n", o);
                        }
                    }
                    //Distance in Columns
                    if(d==1)
                    {
                        //If Diamond
                        if(matrix[n][m]==0)
                        {
                            //If same columns (Distance in Rows)
                            if(p==0)
                            {
                                printf("Hint: There is a Diamond at a distance of %d\n", o);
                                break;
                            }
                            //Different Columns
                            printf("Hint: There is a Diamond at a distance of %d\n", p);
                        }
                        //If Mine
                        if(matrix[n][m]==1)
                        {
                            //If same columns (Distance in Rows)
                            if(p==0)
                            {
                                printf("Beware! There is a Mine at a distance of %d\n", o);
                                break;
                            }
                            //Different Columns
                            printf("Beware! There is a Mine at a distance of %d\n", p);
                        }
                    }
                    break;
                    
                }
            }
        }
        //Win Condition
        if(scr==((size*size)-mine))
        {
            printf("\n\n\tYou Win!!\n\tCongratulations..!! You have Obtained all the Daimonds");
            break;
        }
    }
    
    return 0;
}
