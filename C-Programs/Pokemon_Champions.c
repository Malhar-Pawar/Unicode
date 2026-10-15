#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100

typedef struct
{
    const char *name;
    const char *attackName;
    int attackPower;
    int defensePower;
    int healPower;
} Pokemon;

typedef enum
{
    ATTACK = 1,
    DEFEND,
    HEAL
} Action;

static const Pokemon starters[] = {
    {"Charmander", "Ember", 20, 15, 10},
    {"Squirtle", "Water Gun", 15, 20, 10},
    {"Bulbasaur", "Vine Whip", 15, 15, 15}};

static const Pokemon rivals[] = {
    {"Squirtle", "Water Gun", 25, 20, 10},
    {"Bulbasaur", "Vine Whip", 25, 15, 15},
    {"Charmander", "Ember", 30, 15, 10}};

static int readInteger(const char *prompt, int minimum, int maximum, int *value)
{
    char input[128];

    for (;;)
    {
        char *end;
        long parsed;

        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        parsed = strtol(input, &end, 10);
        while (isspace((unsigned char)*end))
        {
            end++;
        }

        if (end != input && *end == '\0' && parsed >= minimum && parsed <= maximum)
        {
            *value = (int)parsed;
            return 1;
        }

        printf("Please enter a number from %d to %d.\n", minimum, maximum);
    }
}

static int readPlayAgain(void)
{
    char input[128];

    for (;;)
    {
        printf("\nWould you like to play again? (y/n): ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        if (tolower((unsigned char)input[0]) == 'y')
        {
            return 1;
        }
        if (tolower((unsigned char)input[0]) == 'n')
        {
            return 0;
        }

        printf("Please enter y or n.\n");
    }
}

static void displayHealth(const Pokemon *player, int playerHealth,
                          const Pokemon *rival, int rivalHealth)
{
    printf("\n%s: %d/%d HP\t| %s: %d/%d HP\n",
           player->name, playerHealth, MAX_HEALTH,
           rival->name, rivalHealth, MAX_HEALTH);
}

static Action chooseRivalAction(int rivalHealth)
{
    int choice;

    if (rivalHealth <= MAX_HEALTH / 3)
    {
        return HEAL;
    }

    choice = rand() % 10;
    if (choice < 5)
    {
        return ATTACK;
    }
    if (choice < 8)
    {
        return DEFEND;
    }
    return rivalHealth < MAX_HEALTH ? HEAL : ATTACK;
}

static int damageAfterDefense(const Pokemon *attacker, const Pokemon *defender,
                              int defenderIsDefending)
{
    int damage = attacker->attackPower;

    if (defenderIsDefending)
    {
        damage -= defender->defensePower;
    }
    return damage > 0 ? damage : 0;
}

static int heal(const Pokemon *pokemon, int *health)
{
    int recovered = pokemon->healPower;
    int missingHealth = MAX_HEALTH - *health;

    if (recovered > missingHealth)
    {
        recovered = missingHealth;
    }
    *health += recovered;
    return recovered;
}

static int playBattle(const Pokemon *player, const Pokemon *rival)
{
    int playerHealth = MAX_HEALTH;
    int rivalHealth = MAX_HEALTH;
    int turn = 1;

    printf("\n%s, I choose you!\n", player->name);
    printf("Gary sends out %s!\n", rival->name);

    while (playerHealth > 0 && rivalHealth > 0)
    {
        int choice;
        Action playerAction;
        Action rivalAction;

        printf("\n--- Turn %d ---\n", turn++);
        displayHealth(player, playerHealth, rival, rivalHealth);
        printf("1. Attack (%s, %d damage)\n", player->attackName, player->attackPower);
        printf("2. Defend (reduce incoming damage by %d)\n", player->defensePower);
        printf("3. Heal (recover up to %d HP)\n", player->healPower);
        if (!readInteger("Choose your move: ", 1, 3, &choice))
        {
            printf("\nInput ended. The battle is over.\n");
            return 0;
        }

        playerAction = (Action)choice;
        if (playerAction == HEAL && playerHealth == MAX_HEALTH)
        {
            printf("Your Pokemon is already at full health. Choose another move.\n");
            continue;
        }

        rivalAction = chooseRivalAction(rivalHealth);
        if (playerAction == ATTACK)
        {
            int damage = damageAfterDefense(player, rival, rivalAction == DEFEND);
            rivalHealth -= damage;
            if (rivalHealth < 0)
            {
                rivalHealth = 0;
            }
            printf("%s used %s and dealt %d damage!\n",
                   player->name, player->attackName, damage);
        }
        else if (playerAction == DEFEND)
        {
            printf("%s braces for the next attack.\n", player->name);
        }

        if (rivalAction == ATTACK && rivalHealth > 0)
        {
            int damage = damageAfterDefense(rival, player, playerAction == DEFEND);
            playerHealth -= damage;
            if (playerHealth < 0)
            {
                playerHealth = 0;
            }
            printf("%s used %s and dealt %d damage!\n",
                   rival->name, rival->attackName, damage);
        }
        else if (rivalAction == DEFEND)
        {
            printf("%s is defending.\n", rival->name);
        }

        if (playerHealth <= 0 || rivalHealth <= 0)
        {
            break;
        }

        if (playerAction == HEAL)
        {
            printf("%s recovered %d HP.\n", player->name, heal(player, &playerHealth));
        }
        if (rivalAction == HEAL)
        {
            printf("%s recovered %d HP.\n", rival->name, heal(rival, &rivalHealth));
        }
    }

    displayHealth(player, playerHealth, rival, rivalHealth);
    if (playerHealth <= 0 && rivalHealth <= 0)
    {
        printf("Both Pokemon fainted! The battle is a draw.\n");
        return 0;
    }
    if (rivalHealth <= 0)
    {
        printf("%s fainted! You defeated Gary!\n", rival->name);
        return 1;
    }

    printf("%s fainted! Gary won the battle.\n", player->name);
    return 0;
}

int main(void)
{
    int selection;

    srand((unsigned int)time(NULL));
    printf("----- Pokemon Champions -----\n");
    printf("Choose your Pokemon and battle Gary!\n");

    do
    {
        printf("\n1. Charmander (Fire)\n");
        printf("2. Squirtle (Water)\n");
        printf("3. Bulbasaur (Grass)\n");
        if (!readInteger("Choose your starter: ", 1, 3, &selection))
        {
            printf("\nGoodbye!\n");
            return 0;
        }

        printf("\nYou chose %s. Gary chose %s.\n",
               starters[selection - 1].name, rivals[selection - 1].name);
        playBattle(&starters[selection - 1], &rivals[selection - 1]);
    } while (readPlayAgain());

    printf("Thanks for playing Pokemon Champions!\n");
    return 0;
}
