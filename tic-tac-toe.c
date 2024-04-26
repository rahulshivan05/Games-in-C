#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);

            if (j < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }

        printf("\n");

        if (i < BOARD_SIZE - 1)
        {
            printf("-----------\n");
        }
    }

    printf("\n");
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char symbol)
{
    int row, col;

    // check rows
    for (row = 0; row < BOARD_SIZE; row++)
    {
        for (col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] != symbol)
            {
                break;
            }
        }

        if (col == BOARD_SIZE)
        {
            return 1;
        }
    }

    // check columns
    for (col = 0; col < BOARD_SIZE; col++)
    {
        for (row = 0; row < BOARD_SIZE; row++)
        {
            if (board[row][col] != symbol)
            {
                break;
            }
        }

        if (row == BOARD_SIZE)
        {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return 1;
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, turn = 1;
    char symbol;
    srand(time(0));

    printf("Welcome to Tic Tac Toe!\n");

    do
    {
        print_board(board);

        if (turn % 2 == 1)
        {
            symbol = 'X';
        }
        else
        {
            symbol = 'O';
        }

        printf("Player %d (%c), enter row and column (e.g. 1 2): ", (turn % 2) + 1, symbol);
        scanf("%d %d", &row, &col);
        row--;
        col--;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = symbol;

        if (check_win(board, symbol))
        {
            print_board(board);
            printf("Player %d (%c) wins!\n", (turn % 2) + 1, symbol);
            break;
        }

        turn++;

    } while (turn <= BOARD_SIZE * BOARD_SIZE);

    if (turn > BOARD_SIZE * BOARD_SIZE)
    {
        print_board(board);
        printf("Tie game!\n");
    }

    return 0;
}
