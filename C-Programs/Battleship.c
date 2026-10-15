#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define SHIP_COUNT 5
#define MAX_NAME_LENGTH 48
#define MAX_INPUT_LENGTH 128
#define MAX_TARGETS (BOARD_SIZE * BOARD_SIZE * 4)

typedef struct
{
    const char *name;
    int size;
} Ship;

static const Ship fleet[SHIP_COUNT] = {
    {"Aircraft Carrier", 5},
    {"Battleship", 4},
    {"Cruiser", 3},
    {"Submarine", 3},
    {"Patrol Boat", 2}};

static int readLine(char *buffer, size_t size)
{
    size_t length;

    if (fgets(buffer, (int)size, stdin) == NULL)
    {
        return 0;
    }

    length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n')
    {
        buffer[length - 1] = '\0';
    }
    else
    {
        int character;
        while ((character = getchar()) != '\n' && character != EOF)
        {
        }
    }

    return 1;
}

static int readPlacement(int *row, int *column, char *orientation)
{
    char input[MAX_INPUT_LENGTH];
    char extra;

    if (!readLine(input, sizeof(input)))
    {
        return 0;
    }
    if (sscanf(input, " %d %d %c %c", row, column, orientation, &extra) != 3)
    {
        return -1;
    }

    *orientation = (char)toupper((unsigned char)*orientation);
    if (*row < 1 || *row > BOARD_SIZE ||
        *column < 1 || *column > BOARD_SIZE ||
        (*orientation != 'H' && *orientation != 'V'))
    {
        return -1;
    }

    (*row)--;
    (*column)--;
    return 1;
}

static int readTarget(int *row, int *column)
{
    char input[MAX_INPUT_LENGTH];
    char extra;

    if (!readLine(input, sizeof(input)))
    {
        return 0;
    }
    if (sscanf(input, " %d %d %c", row, column, &extra) != 2 ||
        *row < 1 || *row > BOARD_SIZE ||
        *column < 1 || *column > BOARD_SIZE)
    {
        return -1;
    }

    (*row)--;
    (*column)--;
    return 1;
}

static void displayBoards(const char *playerName,
                          int playerShips[BOARD_SIZE][BOARD_SIZE],
                          char playerShots[BOARD_SIZE][BOARD_SIZE],
                          char targetShots[BOARD_SIZE][BOARD_SIZE])
{
    printf("\nYour fleet                              Kraken's waters\n");
    printf("   ");
    for (int column = 1; column <= BOARD_SIZE; column++)
    {
        printf("%2d ", column);
    }
    printf("       ");
    for (int column = 1; column <= BOARD_SIZE; column++)
    {
        printf("%2d ", column);
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        printf("%2d ", row + 1);
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            char mark = playerShots[row][column];
            if (mark == '.')
            {
                mark = playerShips[row][column] == 0 ? '~' : 'S';
            }
            printf(" %c ", mark);
        }

        printf("   %2d ", row + 1);
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            printf(" %c ", targetShots[row][column]);
        }
        printf("\n");
    }

    printf("\nYour fleet: S = ship, X = ship hit, o = incoming miss, ~ = empty water\n");
    printf("Kraken's waters: X = your hit, o = your miss, . = not fired on\n");
    printf("%s's fleet is on the left; your targeting board is on the right.\n\n",
           playerName);
}

static void displayFleetPlacement(int ships[BOARD_SIZE][BOARD_SIZE])
{
    printf("\nYour fleet placement (S = ship, ~ = free water)\n   ");
    for (int column = 1; column <= BOARD_SIZE; column++)
    {
        printf("%2d ", column);
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        printf("%2d ", row + 1);
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            printf(" %c ", ships[row][column] == 0 ? '~' : 'S');
        }
        printf("\n");
    }
    printf("\n");
}

static int canPlaceShip(int board[BOARD_SIZE][BOARD_SIZE],
                        int row, int column, int size, char orientation)
{
    if (orientation == 'H' && column + size > BOARD_SIZE)
    {
        return 0;
    }
    if (orientation == 'V' && row + size > BOARD_SIZE)
    {
        return 0;
    }

    for (int offset = 0; offset < size; offset++)
    {
        int shipRow = row + (orientation == 'V' ? offset : 0);
        int shipColumn = column + (orientation == 'H' ? offset : 0);
        if (board[shipRow][shipColumn] != 0)
        {
            return 0;
        }
    }

    return 1;
}

static void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int shipId,
                      int row, int column, char orientation)
{
    for (int offset = 0; offset < fleet[shipId].size; offset++)
    {
        int shipRow = row + (orientation == 'V' ? offset : 0);
        int shipColumn = column + (orientation == 'H' ? offset : 0);
        board[shipRow][shipColumn] = shipId + 1;
    }
}

static int placePlayerFleet(int board[BOARD_SIZE][BOARD_SIZE])
{
    displayFleetPlacement(board);
    for (int shipId = 0; shipId < SHIP_COUNT; shipId++)
    {
        for (;;)
        {
            int row;
            int column;
            char orientation;
            int result;

            printf("Place your %s (length %d).\n",
                   fleet[shipId].name, fleet[shipId].size);
            printf("Enter row column orientation (H/V), e.g. 3 4 H: ");
            result = readPlacement(&row, &column, &orientation);
            if (result == 0)
            {
                return 0;
            }
            if (result < 0)
            {
                printf("Invalid input. Use row and column 1-10, followed by H or V.\n\n");
                continue;
            }
            if (!canPlaceShip(board, row, column, fleet[shipId].size, orientation))
            {
                printf("That ship does not fit there or overlaps another ship. Try again.\n\n");
                continue;
            }

            placeShip(board, shipId, row, column, orientation);
            printf("%s placed.\n\n", fleet[shipId].name);
            displayFleetPlacement(board);
            break;
        }
    }

    return 1;
}

static void placeComputerFleet(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int shipId = 0; shipId < SHIP_COUNT; shipId++)
    {
        int row;
        int column;
        char orientation;

        do
        {
            row = rand() % BOARD_SIZE;
            column = rand() % BOARD_SIZE;
            orientation = rand() % 2 == 0 ? 'H' : 'V';
        } while (!canPlaceShip(board, row, column, fleet[shipId].size, orientation));

        placeShip(board, shipId, row, column, orientation);
    }
}

static void initializeShots(char shots[BOARD_SIZE][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            shots[row][column] = '.';
        }
    }
}

static int remainingShipCells(const int remaining[SHIP_COUNT])
{
    int cells = 0;
    for (int shipId = 0; shipId < SHIP_COUNT; shipId++)
    {
        cells += remaining[shipId];
    }
    return cells;
}

static void reportHit(int shipId, int remaining[SHIP_COUNT], const char *attacker)
{
    remaining[shipId]--;
    printf("Hit! %s struck the %s.\n", attacker, fleet[shipId].name);
    if (remaining[shipId] == 0)
    {
        printf("%s's %s has been sunk!\n",
               attacker, fleet[shipId].name);
    }
}

static void addComputerTargets(int row, int column, int shots[BOARD_SIZE][BOARD_SIZE],
                               int targets[MAX_TARGETS][2], int *targetCount)
{
    int rowOffsets[] = {-1, 1, 0, 0};
    int columnOffsets[] = {0, 0, -1, 1};

    for (int direction = 3; direction > 0; direction--)
    {
        int other = rand() % (direction + 1);
        int temp = rowOffsets[direction];
        rowOffsets[direction] = rowOffsets[other];
        rowOffsets[other] = temp;
        temp = columnOffsets[direction];
        columnOffsets[direction] = columnOffsets[other];
        columnOffsets[other] = temp;
    }

    for (int direction = 0; direction < 4; direction++)
    {
        int targetRow = row + rowOffsets[direction];
        int targetColumn = column + columnOffsets[direction];
        if (targetRow >= 0 && targetRow < BOARD_SIZE &&
            targetColumn >= 0 && targetColumn < BOARD_SIZE &&
            shots[targetRow][targetColumn] == 0 &&
            *targetCount < MAX_TARGETS)
        {
            targets[*targetCount][0] = targetRow;
            targets[*targetCount][1] = targetColumn;
            (*targetCount)++;
        }
    }
}

static int chooseComputerTarget(int shots[BOARD_SIZE][BOARD_SIZE],
                                int targets[MAX_TARGETS][2], int *targetCount,
                                int *row, int *column)
{
    while (*targetCount > 0)
    {
        int index = --(*targetCount);
        *row = targets[index][0];
        *column = targets[index][1];
        if (shots[*row][*column] == 0)
        {
            return 1;
        }
    }

    {
        int available[BOARD_SIZE * BOARD_SIZE][2];
        int availableCount = 0;

        for (int targetRow = 0; targetRow < BOARD_SIZE; targetRow++)
        {
            for (int targetColumn = 0; targetColumn < BOARD_SIZE; targetColumn++)
            {
                if (shots[targetRow][targetColumn] == 0)
                {
                    available[availableCount][0] = targetRow;
                    available[availableCount][1] = targetColumn;
                    availableCount++;
                }
            }
        }

        if (availableCount == 0)
        {
            return 0;
        }

        {
            int choice = rand() % availableCount;
            *row = available[choice][0];
            *column = available[choice][1];
        }
    }
    return 1;
}

int main(void)
{
    int computerShips[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int playerShips[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int playerRemaining[SHIP_COUNT];
    int computerRemaining[SHIP_COUNT];
    int computerShots[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int targets[MAX_TARGETS][2];
    int targetCount = 0;
    char playerShots[BOARD_SIZE][BOARD_SIZE];
    char computerShotMarks[BOARD_SIZE][BOARD_SIZE];
    char playerName[MAX_NAME_LENGTH + 1];

    srand((unsigned int)time(NULL));
    for (int shipId = 0; shipId < SHIP_COUNT; shipId++)
    {
        playerRemaining[shipId] = fleet[shipId].size;
        computerRemaining[shipId] = fleet[shipId].size;
    }
    printf("========== BATTLESHIP ==========\n");
    printf("Sink all 17 sections of Mr. Kraken's fleet to win.\n");
    printf("Rows and columns are numbered 1-10. Ships are placed horizontally or vertically.\n");
    printf("Enter your name: ");
    if (!readLine(playerName, sizeof(playerName)))
    {
        printf("\nGoodbye!\n");
        return 0;
    }
    if (playerName[0] == '\0')
    {
        strcpy(playerName, "Captain");
    }

    initializeShots(playerShots);
    initializeShots(computerShotMarks);
    placeComputerFleet(computerShips);

    printf("\n%s, place your fleet. Ships may touch but cannot overlap.\n\n", playerName);
    if (!placePlayerFleet(playerShips))
    {
        printf("\nInput ended during fleet placement. Goodbye!\n");
        return 0;
    }

    printf("\nYour fleet is ready. Let the battle begin!\n");
    displayBoards(playerName, playerShips, computerShotMarks, playerShots);

    while (remainingShipCells(computerRemaining) > 0 &&
           remainingShipCells(playerRemaining) > 0)
    {
        int row;
        int column;
        int result;

        for (;;)
        {
            printf("%s's turn (%d enemy ship sections remaining).\n",
                   playerName, remainingShipCells(computerRemaining));
            printf("Fire at row column (1-10 1-10): ");
            result = readTarget(&row, &column);
            if (result == 0)
            {
                printf("\nInput ended. The battle is over.\n");
                return 0;
            }
            if (result < 0)
            {
                printf("Invalid coordinates. Enter two numbers from 1 to 10.\n");
                continue;
            }
            if (playerShots[row][column] != '.')
            {
                printf("You already fired there. Choose a different target.\n");
                continue;
            }
            break;
        }

        if (computerShips[row][column] > 0)
        {
            int shipId = computerShips[row][column] - 1;
            playerShots[row][column] = 'X';
            reportHit(shipId, computerRemaining, playerName);
            if (remainingShipCells(computerRemaining) == 0)
            {
                break;
            }
            printf("Direct hit! You get another shot.\n\n");
            displayBoards(playerName, playerShips, computerShotMarks, playerShots);
            continue;
        }

        playerShots[row][column] = 'o';
        printf("Miss!\n\n");

        do
        {
            if (!chooseComputerTarget(computerShots, targets, &targetCount,
                                      &row, &column))
            {
                break;
            }

            printf("Mr. Kraken fires at row %d, column %d: ",
                   row + 1, column + 1);
            computerShots[row][column] = 1;
            if (playerShips[row][column] > 0)
            {
                int shipId = playerShips[row][column] - 1;
                computerShotMarks[row][column] = 'X';
                reportHit(shipId, playerRemaining, "Mr. Kraken");
                if (remainingShipCells(playerRemaining) == 0)
                {
                    break;
                }
                if (computerRemaining[shipId] == 0)
                {
                    targetCount = 0;
                }
                else
                {
                    addComputerTargets(row, column, computerShots, targets, &targetCount);
                }
            }
            else
            {
                computerShotMarks[row][column] = 'o';
                printf("Miss.\n");
                break;
            }
        } while (remainingShipCells(playerRemaining) > 0);

        printf("\n");
        displayBoards(playerName, playerShips, computerShotMarks, playerShots);
    }

    if (remainingShipCells(computerRemaining) == 0)
    {
        printf("Victory, %s! You sank Mr. Kraken's entire fleet!\n", playerName);
    }
    else
    {
        printf("Mr. Kraken sank your fleet. Better luck next time, %s!\n", playerName);
    }

    return 0;
}
