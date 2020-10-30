#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH (20)
#define NUM_PATTERNS (12)

int drow_1[NUM_PATTERNS] = {-1, 0, 1, 0, 1, 0, -1, 0, 1, 0, -1, 0};
int dcol_1[NUM_PATTERNS] = {0, 1, 0, -1, 0, -1, 0, 1, 0, -1, 0, 1};
int drow_2[NUM_PATTERNS] = {0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};
int dcol_2[NUM_PATTERNS] = {1, 0, -1, 0, 1, -1, -1, 1, -1, -1, 1, 1};

// void print_board(char (*board)[MAX_LENGTH], int height, int width)
// {
//     printf("\n");
//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             printf("%c", board[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

bool is_out_of_range(int row, int col, int height, int width)
{
    if (row < 0 || col < 0 || row >= height || col >= width)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_valid_cell(int row, int col, char (*board)[MAX_LENGTH], int height, int width)
{
    if (is_out_of_range(row, col, height, width) == true)
    {
        return false;
    }
    else
    {
        if (board[row][col] == '.')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int find_num_coverages(char (*board)[MAX_LENGTH], int height, int width)
{
    int first_find_row = -1;
    int first_find_col = -1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] == '.')
            {
                first_find_row = i;
                first_find_col = j;
                break;
            }
        }

        if (first_find_row != -1 && first_find_col != -1)
        {
            break;
        }
    }

    if (first_find_row == -1 && first_find_col == -1)
    {
        return 1;
    }

    int ret = 0;
    int i = first_find_row;
    int j = first_find_col;

    for (int k = 0; k < NUM_PATTERNS; k++)
    {
        if (is_valid_cell(i, j, board, height, width) && is_valid_cell(i + drow_1[k], j + dcol_1[k], board, height, width) && is_valid_cell(i + drow_2[k], j + dcol_2[k], board, height, width))
        {
            board[i][j] = '#';
            board[i + drow_1[k]][j + dcol_1[k]] = '#';
            board[i + drow_2[k]][j + dcol_2[k]] = '#';
            // print_board(board, height, width);
            ret += find_num_coverages(board, height, width);
            board[i][j] = '.';
            board[i + drow_1[k]][j + dcol_1[k]] = '.';
            board[i + drow_2[k]][j + dcol_2[k]] = '.';
        }
    }

    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);

    for (int tc = 0; tc < C; tc++)
    {
        int H, W;
        char board[MAX_LENGTH][MAX_LENGTH] = {0};

        scanf("%d %d\n", &H, &W);

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                scanf("%c\n", &board[i][j]);
            }
        }

        int num_coverages = find_num_coverages(board, H, W);
        printf("%d\n", num_coverages);
    }
}