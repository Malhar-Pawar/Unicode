#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 10

void GI(char *ptr)
{
	printf("\t\t\t\t\t-----Battleship-----\n\n");
	printf("Enter Your Name:\t");
	scanf(" %19s", ptr);
	printf("\nHey %s\n\tWelcome to a Classic Game of Battleship.\n\tYou will be Competing Against Mr.Kraken.\n\tBoth Players would place their ships on a 10x10 Grid.\n\tFirst Player to sink all the opponent's ship Wins the Game.\n", ptr);
	printf("\nLet us Look at the Ships to be Placed and their Sizes:\n1.\tAirCraft Carrier\t: 5 Squares\n2.\tBattleship\t: 4 Squares\n3.\tCruiser\t\t: 3 Squares\n4.\tSubmarine\t: 3 Squares\n5.\tPatrol Boat\t: 2 Squares\n\n");
}

void DispPLRboard(char arr[][N], char *ptr)
{
	printf("%c\t\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n\n", ptr[0]);
	for(int i=0; i<10; i++)
	{
		printf("%d\t\t",i);
		for(int j=0; j<10; j++)
		{
			printf("%c\t", arr[i][j]);
		}
		printf("\n");
	}
}
void DispBOTboard(char arr[][N])
{
	printf("KN\t\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n\n");
	for(int i=0; i<10; i++)
	{
		printf("%d\t\t",i);
		for(int j=0; j<10; j++)
		{
			printf("%c\t", arr[i][j]);
		}
		printf("\n");
	}
}

void Kraken(int arr[][N])
{
	//initializations
	int a,b,df;

	//Aircraft Carrier
	while(1)
	{
		a=(rand()%10);
		b=(rand()%10);
		df=(rand()%2)+1;

		if(df==1)
		{
			if(a<=5)
			{
				for(int z=0; z<5; z++)
				{
					arr[a+z][b]=1;
				}
				break;
			}
			if(a>=4)
			{
				for(int z=0; z<5; z++)
				{
					arr[a-z][b]=1;
				}
				break;
			}
		}
		if(df==2)
		{
			if(b<=5)
			{
				for(int z=0; z<5; z++)
				{
					arr[a][b+z]=1;
				}
				break;
			}
			if(b>=4)
			{
				for(int z=0; z<5; z++)
				{
					arr[a][b-z]=1;
				}
				break;
			}
		}
	}

	//Battleship
	while(1)
	{
		a=(rand()%10);
		b=(rand()%10);
		df=(rand()%2)+1;
		int inspect;

		if(df==1)
		{
			if(a<=6)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[a+z][b]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[a+z][b]=1;
					}
					break;
				}
			}
			if(a>=3)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[a-z][b]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[a-z][b]=1;
					}
					break;
				}
			}
		}
		if(df==2)
		{
			if(b<=6)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[a][b+z]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[a][b+z]=1;
					}
					break;
				}
			}
			if(b>=3)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[a][b-z]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[a][b-z]=1;
					}
					break;
				}
			}
		}
	}

	//Cruiser
	while(1)
	{
		a=(rand()%10);
		b=(rand()%10);
		df=(rand()%2)+1;
		int inspect;

		if(df==1)
		{
			if(a<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a+z][b]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a+z][b]=1;
					}
					break;
				}
			}
			if(a>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a-z][b]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a-z][b]=1;
					}
					break;
				}
			}
		}
		if(df==2)
		{
			if(b<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a][b+z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a][b+z]=1;
					}
					break;
				}
			}
			if(b>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a][b-z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a][b-z]=1;
					}
					break;
				}
			}
		}
	}

	//Submarine
	while(1)
	{
		a=(rand()%10);
		b=(rand()%10);
		df=(rand()%2)+1;
		int inspect;

		if(df==1)
		{
			if(a<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a+z][b]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a+z][b]=1;
					}
					break;
				}
			}
			if(a>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a-z][b]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a-z][b]=1;
					}
					break;
				}
			}
		}
		if(df==2)
		{
			if(b<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a][b+z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a][b+z]=1;
					}
					break;
				}
			}
			if(b>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[a][b-z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[a][b-z]=1;
					}
					break;
				}
			}
		}
	}

	//Patrol Boat
	while(1)
	{
		a=(rand()%10);
		b=(rand()%10);
		df=(rand()%2)+1;
		int inspect;

		if(df==1)
		{
			if(a<=8)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[a+z][b]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[a+z][b]=1;
					}
					break;
				}
			}
			if(a>=1)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[a-z][b]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[a-z][b]=1;
					}
					break;
				}
			}
		}
		if(df==2)
		{
			if(b<=8)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[a][b+z]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[a][b+z]=1;
					}
					break;
				}
			}
			if(b>=1)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[a][b-z]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[a][b-z]=1;
					}
					break;
				}
			}
		}
	}
}

void PShip(int arr[][N], char darr[][N], char *ptr)
{
	//initializations
	int x,y,dir,inspect;

	//DispPLRboard(darr, ptr);

	//Aircraft Carrier
	while(1)
	{
		//Co-ordinates, Orientation and Input Validation
		DispPLRboard(darr, ptr);
		printf("\nPlace your Aircraft Carrier:\t");
		scanf(" %d %d", &x, &y);
		if(x<0 || x>9 || y<0 || y>9)
		{
			printf("Invalid Co-ordinates\n\n");
			continue;
		}
		printf("Select Orientation:\n1.\tVertical UP\n2.\tVertical DOWN\n3.\tHorizontal RIGHT\n4.\tHorizontal LEFT\n\n");
		scanf(" %d", &dir);
		if(dir<1 || dir>4)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Ship Placement
		if(dir==1)
		{
			if(x>=4)
			{
				inspect=0;
				for(int z=0; z<5; z++)
				{
					if(arr[x-z][y]==0) inspect++;
				}
				if(inspect==5)
				{
					for(int z=0; z<5; z++)
					{
						arr[x-z][y]=1;
						darr[x-z][y]='#';
					}
					printf("Aircraft Carrier Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==2)
		{
			if(x<=5)
			{
				inspect=0;
				for(int z=0; z<5; z++)
				{
					if(arr[x+z][y]==0) inspect++;
				}
				if(inspect==5)
				{
					for(int z=0; z<5; z++)
					{
						arr[x+z][y]=1;
						darr[x+z][y]='#';
					}
					printf("Aircraft Carrier Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==3)
		{
			if(y<=5)
			{
				inspect=0;
				for(int z=0; z<5; z++)
				{
					if(arr[x][y+z]==0) inspect++;
				}
				if(inspect==5)
				{
					for(int z=0; z<5; z++)
					{
						arr[x][y+z]=1;
						darr[x][y+z]='#';
					}
					printf("Aircraft Carrier Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==4)
		{
			if(y>=4)
			{
				inspect=0;
				for(int z=0; z<5; z++)
				{
					if(arr[x][y-z]==0) inspect++;
				}
				if(inspect==5)
				{
					for(int z=0; z<5; z++)
					{
						arr[x][y-z]=1;
						darr[x][y-z]='#';
					}
					printf("Aircraft Carrier Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
	}

	//Battleship
	while(1)
	{
		//Co-ordinates, Orientation and Input Validation
		DispPLRboard(darr, ptr);
		printf("\nPlace your Battleship:\t");
		scanf(" %d %d", &x, &y);
		if(x<0 || x>9 || y<0 || y>9)
		{
			printf("Invalid Co-ordinates\n\n");
			continue;
		}
		if(arr[x][y]==1)
		{
			printf("Space Occupied\nTry another Co-ordinates\n\n");
			continue;
		}
		printf("Select Orientation:\n1.\tVertical UP\n2.\tVertical DOWN\n3.\tHorizontal RIGHT\n4.\tHorizontal LEFT\n\n");
		scanf(" %d", &dir);
		if(dir<1 || dir>4)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Ship Placement
		if(dir==1)
		{
			if(x>=3)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[x-z][y]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[x-z][y]=1;
						darr[x-z][y]='#';
					}
					printf("Battleship Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==2)
		{
			if(x<=6)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[x+z][y]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[x+z][y]=1;
						darr[x+z][y]='#';
					}
					printf("Battleship Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==3)
		{
			if(y<=6)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[x][y+z]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[x][y+z]=1;
						darr[x][y+z]='#';
					}
					printf("Battleship Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==4)
		{
			if(y>=3)
			{
				inspect=0;
				for(int z=0; z<4; z++)
				{
					if(arr[x][y-z]==0) inspect++;
				}
				if(inspect==4)
				{
					for(int z=0; z<4; z++)
					{
						arr[x][y-z]=1;
						darr[x][y-z]='#';
					}
					printf("Battleship Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
	}

	//Cruiser
	while(1)
	{
		//Co-ordinates, Orientation and Input Validation
		DispPLRboard(darr, ptr);
		printf("\nPlace your Cruiser:\t");
		scanf(" %d %d", &x, &y);
		if(x<0 || x>9 || y<0 || y>9)
		{
			printf("Invalid Co-ordinates\n\n");
			continue;
		}
		if(arr[x][y]==1)
		{
			printf("Space Occupied\nTry another Co-ordinates\n\n");
			continue;
		}
		printf("Select Orientation:\n1.\tVertical UP\n2.\tVertical DOWN\n3.\tHorizontal RIGHT\n4.\tHorizontal LEFT\n\n");
		scanf(" %d", &dir);
		if(dir<1 || dir>4)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Ship Placement
		if(dir==1)
		{
			if(x>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x-z][y]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x-z][y]=1;
						darr[x-z][y]='#';
					}
					printf("Cruiser Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==2)
		{
			if(x<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x+z][y]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x+z][y]=1;
						darr[x+z][y]='#';
					}
					printf("Cruiser Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==3)
		{
			if(y<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x][y+z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x][y+z]=1;
						darr[x][y+z]='#';
					}
					printf("Cruiser Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==4)
		{
			if(y>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x][y-z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x][y-z]=1;
						darr[x][y-z]='#';
					}
					printf("Cruiser Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
	}

	//Submarine
	while(1)
	{
		//Co-ordinates, Orientation and Input Validation
		DispPLRboard(darr, ptr);
		printf("\nPlace your Submarine:\t");
		scanf(" %d %d", &x, &y);
		if(x<0 || x>9 || y<0 || y>9)
		{
			printf("Invalid Co-ordinates\n\n");
			continue;
		}
		if(arr[x][y]==1)
		{
			printf("Space Occupied\nTry another Co-ordinates\n\n");
			continue;
		}
		printf("Select Orientation:\n1.\tVertical UP\n2.\tVertical DOWN\n3.\tHorizontal RIGHT\n4.\tHorizontal LEFT\n\n");
		scanf(" %d", &dir);
		if(dir<1 || dir>4)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Ship Placement
		if(dir==1)
		{
			if(x>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x-z][y]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x-z][y]=1;
						darr[x-z][y]='#';
					}
					printf("Submarine Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==2)
		{
			if(x<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x+z][y]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x+z][y]=1;
						darr[x+z][y]='#';
					}
					printf("Submarine Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==3)
		{
			if(y<=7)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x][y+z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x][y+z]=1;
						darr[x][y+z]='#';
					}
					printf("Submarine Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==4)
		{
			if(y>=2)
			{
				inspect=0;
				for(int z=0; z<3; z++)
				{
					if(arr[x][y-z]==0) inspect++;
				}
				if(inspect==3)
				{
					for(int z=0; z<3; z++)
					{
						arr[x][y-z]=1;
						darr[x][y-z]='#';
					}
					printf("Submarine Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
	}

	//Patrol Boat
	while(1)
	{
		//Co-ordinates, Orientation and Input Validation
		DispPLRboard(darr, ptr);
		printf("\nPlace your Patrol Boat:\t");
		scanf(" %d %d", &x, &y);
		if(x<0 || x>9 || y<0 || y>9)
		{
			printf("Invalid Co-ordinates\n\n");
			continue;
		}
		if(arr[x][y]==1)
		{
			printf("Space Occupied\nTry another Co-ordinates\n\n");
			continue;
		}
		printf("Select Orientation:\n1.\tVertical UP\n2.\tVertical DOWN\n3.\tHorizontal RIGHT\n4.\tHorizontal LEFT\n\n");
		scanf(" %d", &dir);
		if(dir<1 || dir>4)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Ship Placement
		if(dir==1)
		{
			if(x>=1)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[x-z][y]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[x-z][y]=1;
						darr[x-z][y]='#';
					}
					printf("Patrol Boat Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==2)
		{
			if(x<=8)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[x+z][y]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[x+z][y]=1;
						darr[x+z][y]='#';
					}
					printf("Patrol Boat Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==3)
		{
			if(y<=8)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[x][y+z]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[x][y+z]=1;
						darr[x][y+z]='#';
					}
					printf("Patrol Boat Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
		if(dir==4)
		{
			if(y>=1)
			{
				inspect=0;
				for(int z=0; z<2; z++)
				{
					if(arr[x][y-z]==0) inspect++;
				}
				if(inspect==2)
				{
					for(int z=0; z<2; z++)
					{
						arr[x][y-z]=1;
						darr[x][y-z]='#';
					}
					printf("Patrol Boat Placed Successfully\n\n");
					break;
				}
				else
				{
					printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
				}
			}
			else
			{
				printf("Ship Placement Unsuccessfull\nPlease Try different Co-ordinates\n\n");
			}
		}
	}
	printf("Combat Zone is Ready..!\n\n");
}

int main()
{
	//Battlefield Setup
	int Botmat[10][10];
	int PLRmat[10][10];
	char dispBotmat[10][10];
	char dispPLRmat[10][10];
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			Botmat[i][j]=0;
			PLRmat[i][j]=0;
			dispBotmat[i][j]='.';
			dispPLRmat[i][j]='.';
		}
	}

	//Initializations
	int x,y,PLRSCR=0,KNSCR=0;
	srand(time(0));
	char name[20];
	char *pt;
	pt= &name[0];

	GI(pt);     //Game Intro

	//Kraken Ship Placement
	Kraken(Botmat);
	//Player Ship Placement
	PShip(PLRmat, dispPLRmat, pt);

	//Game Loop
	while(1)
	{
		//Player Turn
		printf("%s's Turn\t[Score: %d ]\n",name, PLRSCR);
		DispBOTboard(dispBotmat);
		printf("\nTarget Co-ordinates:\t");
		scanf(" %d %d", &x, &y);
		if(x<0 || x>9 || y<0 || y>9)
		{
			printf("Invalid Co-ordinates\nTry Again\n\n");
			continue;
		}
		if(dispBotmat[x][y]=='X' || dispBotmat[x][y]=='O')
		{
			printf("Already Hit...Try Different Co-ordinates\n\n");
			continue;
		}
		if(Botmat[x][y]==1)
		{
			printf("Hit!!");
			dispBotmat[x][y]='X';
			PLRSCR++;
			if(PLRSCR!=17)
			{
				printf(" Take Another Shot..!\n\n");
				continue;
			}
			printf("\n\n");
		}
		if(Botmat[x][y]==0)
		{
			printf("Miss..!\n\n");
			dispBotmat[x][y]='O';
		}

		//End Check
		if(PLRSCR==17 || KNSCR==17)
		{
			if(PLRSCR==17)
			{
				printf("Congratulations! You won the Game..!!\n");
			}
			if(KNSCR==17)
			{
				printf("You Lost to Mr.Kraken..!\n");
			}
			break;
		}

		printf("Mr.Kraken's Turn\t[Score: %d ]\n",KNSCR);
		//Mr.Kraken
		while(1)
		{
			x=(rand()%10);
			y=(rand()%10);
			if(dispPLRmat[x][y]=='X' || dispPLRmat[x][y]=='O')
			{
				continue;
			}
			printf("Mr.Kraken Fires at: %d %d\n", x,y);
			if(PLRmat[x][y]==0)
			{
				printf("Miss..!\n\n");
				dispPLRmat[x][y]='O';
				break;
			}
			if(PLRmat[x][y]==1)
			{
				printf("Hit!! ");
				dispPLRmat[x][y]='X';
				KNSCR++;
				if(KNSCR==17) break;
				printf("Take Another Shot..!\n\n");
				continue;
			}
		}
		DispPLRboard(dispPLRmat, pt);
		printf("\n");

		//End Check
		if(PLRSCR==17 || KNSCR==17)
		{
			if(PLRSCR==17)
			{
				printf("Congratulations! You won the Game..!!\n");
			}
			if(KNSCR==17)
			{
				printf("You Lost to Mr.Kraken..!\n");
			}
			break;
		}
	}
}
