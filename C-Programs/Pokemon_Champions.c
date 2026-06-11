#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int MvRvl()     //Move Selector
{
	int mv;
	mv=(rand()%9)+1;
	return mv;
}

// Structure definition
struct Pokedex {
	int DexNo;
	char PmName[12];
};

void GI(void)       //Game Intro
{
	printf("\t\t\t\t\t-----Pokemon Champions-----\n\n");
	printf("Prof. Oak: Hey Ash, I am Professor Oak, glad to meet you! Gary and Me were waiting for you.\n\tBoth of you are officially going to begin with your Pokemon Journey.\n\tFor that, you need a partner to accompany you!\n\tI have 3 Starter Pokemons to Offer:\n\t1.\tCharmander: The Fire Type Pokemon\n\t2.\tSquirtle: The Water Type Pokemon\n\t3.\tBulbasaur: The Grass Type Pokemon\n\n");
	printf("Prof.Oak: Gary, go on! Choose your Pokemon..!\nGary: I would like to give this Opportunity to Ash. He may choose his Pokemon First.\nProf. Oak: Alright Ash, Choose your Pokemon..!\n\n");
}

int FoePoke(int P)      //Gary's Pokemon
{
	int R;
	switch(P)
	{
	case 1:
	{
		R=2;
		break;
	}
	case 2:
	{
		R=3;
		break;
	}
	case 3:
	{
		R=1;
		break;
	}
	}
	return R;
}
void Fire(struct Pokedex *p)    //Charmander VS Squirtle
{
	//Initialization
	int Uatk=20, Udef=15, Uheal=10;
	int Ratk=25, Rdef=20, Rheal=10;
	int fireliz=100, watertort=100;
	int UserMV, RvlMV;
	int UD=0,RD=0;

	//Game Loop
	while(1)
	{
		//Battle Options and User-Rival Input
		printf("What will %s do?\n", p[0].PmName);
		printf("1.\tAttack\n2.\tDefend\n3.\tHeal\n");
		scanf(" %d", &UserMV);
		if(UserMV<1 || UserMV>3)
		{
			printf("Invalid Selection\n\n");
			continue;
		}
		RvlMV=MvRvl();

		//Defence of both Parties
		if(UserMV==2)
		{
			printf("\tCharmander Used Defence Curl\n");
			UD=1;
		}
		if(RvlMV>4 && RvlMV<8)
		{
			printf("\tSquirtle Used Defence Curl\n");
			RD=1;
		}

		//Attack
		if(UserMV==1)
		{
			printf("\tCharmander Used Ember\n");
			if(RD==0)
			{
				watertort-=Uatk;
			}
			if(RD==1)
			{
				watertort-=(abs(Uatk-Rdef));
				RD--;
			}
		}
		if(watertort<=0 || fireliz<=0)      //End Check
		{
			if(watertort<=0)
			{
				printf("\nSquirtle Fainted..!\nCharmander Won the Battle\n\nYou Defeated Rival Gary!!");
			}
			if(fireliz<=0)
			{
				printf("\nCharmander Fainted..!\nSquirtle Won the Battle\n\nRival Gary Defeated you!!");
			}
			break;
		}
		if(RvlMV<5)
		{
			printf("\tSquirtle Used Water Gun\n");
			if(UD==0)
			{
				fireliz-=Ratk;
			}
			if(UD==1)
			{
				fireliz-=(abs(Ratk-Udef));
				UD--;
			}
		}
		if(watertort<=0 || fireliz<=0)      //End Check
		{
			if(watertort<=0)
			{
				printf("\nSquirtle Fainted..!\nCharmander Won the Battle\n\nYou Defeated Rival Gary!!");
			}
			if(fireliz<=0)
			{
				printf("\nCharmander Fainted..!\nSquirtle Won the Battle\n\nRival Gary Defeated you!!");
			}
			break;
		}

		//Healing for Both Parties
		if(UserMV==3)
		{
			printf("\tCharmander Used Heal Bell\n");
			fireliz+=Uheal;
			if(fireliz>100) fireliz=100;
		}
		if(RvlMV>7)
		{
			printf("\tSquirtle Used Heal Bell\n");
			watertort+=Rheal;
			if(watertort>100) watertort=100;
		}

		//After-Move
		printf("\nCharmander\t: %d/100\nSquirtle\t: %d/100\n\n", fireliz, watertort);
		if(RD==1) RD--;
		if(UD==1) UD--;
	}
}

void Water(struct Pokedex *p)   //Squirtle VS Bulbasaur
{
	//Initialization
	int Uatk=15, Udef=20, Uheal=10;
	int Ratk=25, Rdef=15, Rheal=15;
	int grassbulb=100, watertort=100;
	int UserMV, RvlMV;
	int UD=0,RD=0;

	//Game Loop
	while(1)
	{
		//Battle Options and User-Rival Input
		printf("What will %s do?\n", p[1].PmName);
		printf("1.\tAttack\n2.\tDefend\n3.\tHeal\n");
		scanf(" %d", &UserMV);
		if(UserMV<1 || UserMV>3)
		{
			printf("Invalid Selection\n\n");
			continue;
		}
		RvlMV=MvRvl();

		//Defence of both Parties
		if(UserMV==2)
		{
			printf("\tSquirtle Used Defence Curl\n");
			UD=1;
		}
		if(RvlMV>4 && RvlMV<8)
		{
			printf("\tBulbasaur Used Defence Curl\n");
			RD=1;
		}

		//Attack
		if(UserMV==1)
		{
			printf("\tSquirtle Used Water Gun\n");
			if(RD==0)
			{
				grassbulb-=Uatk;
			}
			if(RD==1)
			{
				grassbulb-=(abs(Uatk-Rdef));
				RD--;
			}
		}
		if(watertort<=0 || grassbulb<=0)      //End Check
		{
			if(grassbulb<=0)
			{
				printf("\nBulbasaur Fainted..!\nSquirtle Won the Battle\n\nYou Defeated Rival Gary!!");
			}
			if(watertort<=0)
			{
				printf("\nSquirtle Fainted..!\nBulbasaur Won the Battle\n\nRival Gary Defeated you!!");
			}
			break;
		}
		if(RvlMV<5)
		{
			printf("\tBulbasaur Used Vine Whip\n");
			if(UD==0)
			{
				watertort-=Ratk;
			}
			if(UD==1)
			{
				watertort-=(abs(Ratk-Udef));
				UD--;
			}
		}
		if(watertort<=0 || grassbulb<=0)      //End Check
		{
			if(grassbulb<=0)
			{
				printf("\nBulbasaur Fainted..!\nSquirtle Won the Battle\n\nYou Defeated Rival Gary!!");
			}
			if(watertort<=0)
			{
				printf("\nSquirtle Fainted..!\nBulbasaur Won the Battle\n\nRival Gary Defeated you!!");
			}
			break;
		}

		//Healing for Both Parties
		if(UserMV==3)
		{
			printf("\tSquirtle Used Heal Bell\n");
			watertort+=Uheal;
			if(watertort>100) watertort=100;
		}
		if(RvlMV>7)
		{
			printf("\tBulbasaur Used Heal Bell\n");
			grassbulb+=Rheal;
			if(grassbulb>100) grassbulb=100;
		}

		//After-Move
		printf("\nSquirtle\t: %d/100\nBulbasaur\t: %d/100\n\n", watertort, grassbulb);
		if(RD==1) RD--;
		if(UD==1) UD--;
	}
}

void Grass(struct Pokedex *p)   //Bulbasaur VS Charmander
{
	//Initialization
	int Uatk=15, Udef=15, Uheal=15;
	int Ratk=30, Rdef=15, Rheal=10;
	int grassbulb=100, fireliz=100;
	int UserMV, RvlMV;
	int UD=0,RD=0;

	//Game Loop
	while(1)
	{
		//Battle Options and User-Rival Input
		printf("What will %s do?\n", p[2].PmName);
		printf("1.\tAttack\n2.\tDefend\n3.\tHeal\n");
		scanf(" %d", &UserMV);
		if(UserMV<1 || UserMV>3)
		{
			printf("Invalid Selection\n\n");
			continue;
		}
		RvlMV=MvRvl();

		//Defence of both Parties
		if(UserMV==2)
		{
			printf("\tBulbasaur Used Defence Curl\n");
			UD=1;
		}
		if(RvlMV>4 && RvlMV<8)
		{
			printf("\tCharmander Used Defence Curl\n");
			RD=1;
		}

		//Attack
		if(UserMV==1)
		{
			printf("\tBulbasaur Used Vine Whip\n");
			if(RD==0)
			{
				fireliz-=Uatk;
			}
			if(RD==1)
			{
				fireliz-=(abs(Uatk-Rdef));
				RD--;
			}
		}
		if(fireliz<=0 || grassbulb<=0)      //End Check
		{
			if(fireliz<=0)
			{
				printf("\nCharmander Fainted..!\nBulbasaur Won the Battle\n\nYou Defeated Rival Gary!!");
			}
			if(grassbulb<=0)
			{
				printf("\nBulbasaur Fainted..!\nCharmander Won the Battle\n\nRival Gary Defeated you!!");
			}
			break;
		}
		if(RvlMV<5)
		{
			printf("\tCharmander Used Ember\n");
			if(UD==0)
			{
				grassbulb-=Ratk;
			}
			if(UD==1)
			{
				grassbulb-=(abs(Ratk-Udef));
				UD--;
			}
		}
		if(fireliz<=0 || grassbulb<=0)      //End Check
		{
			if(fireliz<=0)
			{
				printf("\nCharmander Fainted..!\nBulbasaur Won the Battle\n\nYou Defeated Rival Gary!!");
			}
			if(grassbulb<=0)
			{
				printf("\nBulbasaur Fainted..!\nCharmander Won the Battle\n\nRival Gary Defeated you!!");
			}
			break;
		}

		//Healing for Both Parties
		if(UserMV==3)
		{
			printf("\tBulbasaur Used Heal Bell\n");
			grassbulb+=Uheal;
			if(grassbulb>100) grassbulb=100;
		}
		if(RvlMV>7)
		{
			printf("\tCharmander Used Heal Bell\n");
			fireliz+=Rheal;
			if(fireliz>100) fireliz=100;
		}

		//After-Move
		printf("\nBulbasaur\t: %d/100\nCharmander\t: %d/100\n\n", grassbulb, fireliz);
		if(RD==1) RD--;
		if(UD==1) UD--;
	}
}

int main()
{
	//Structure
	struct Pokedex PMN[3] = {
		{1, "Charmander"},
		{2, "Squirtle"},
		{3, "Bulbasaur"}
	};
	struct Pokedex *ptr;
	ptr = &PMN[0];

	//Initializations
	int UserPoke, RvlPoke;
	srand(time(0));

	//Game Intro
	GI();

	//Pokemon Selection
	while(1)
	{
		printf("What do You Choose..?\n");
		printf("1.\tCharmander\t: The Fire Type Pokemon\n2.\tSquirtle\t: The Water Type Pokemon\n3.\tBulbasaur\t: The Grass Type Pokemon\n\n");
		scanf(" %d", &UserPoke);
		if(UserPoke<1 || UserPoke>3)
		{
			printf("Invalid Selection\n\n");
			continue;
		}
		break;
	}
	printf("Ash Chose %s\n", ptr[UserPoke-1].PmName);
	RvlPoke=FoePoke(UserPoke);
	printf("Gary Chose %s\n\n", ptr[RvlPoke-1].PmName);

	//Battle
	printf("Gary: Alright Ash! Since we got out First Pokemon, Let's test the in the Battle..!\nProf Oak: Let me guide you through the Battle.\n\n");
	printf("You have 3 options to Choose from:\n1.\tAttack:\tDamage Rival Pokemon\n2.\tDefend:\tDefend Your Pokemon\n3.\tHeal:\tRecover Your Pokemon's Health\nLet the Battle Begin..!\n\n");
	printf("Ash: Go %s..!\n", ptr[UserPoke-1].PmName);
	RvlPoke=FoePoke(UserPoke);
	printf("Gary: Go %s..!\n\n", ptr[RvlPoke-1].PmName);

	//Game Loop
	switch(UserPoke)
	{
	case 1:
	{
		Fire(ptr);  //User Choose Charmander
		break;
	}
	case 2:
	{
		Water(ptr); //User Choose Squirtle
		break;
	}
	case 3:
	{
		Grass(ptr); //User Choose Bulbasaur
		break;
	}
	}
	return 0;
}
