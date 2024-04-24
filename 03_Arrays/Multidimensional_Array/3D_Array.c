#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

bool isSafe(int square[5][5], int x, int y, int visited[5][5])
{
    if (square[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char makeamove(int square[5][5], int x, int y, int visited[5][5])
{
    if (square[x + 1][y])
    {
        return 'D';
    }
    else if (square[x][y + 1])
    {
        return 'L';
    }
}

int main()
{
    // arr[j][j]
    // arr[row][col]

    int visited[5][5] = {{0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};

    int square[5][5] = {{1, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 1, 1}};

    // int row = sizeof(square);
    // int row2 = sizeof(square) / sizeof(int) / 5;
    // printf("%d \n", row);
    // printf("%d \n", row2);

    // Traversing the Square
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // Checking if it is safe
            if (isSafe(square, i, j, visited))
            {
                // printf("Safe to Move \n");
                visited[i][j] = 1;
                if (square[i + 1][j])
                {
                    printf("%c", 'D');
                    visited[i][j] = 1;
                }
                else if (square[i - 1][j])
                {
                    printf("%c", 'L');
                    visited[i][j] = 1;
                }
                else if (square[i][j + 1])
                {
                    printf("%c", 'R');
                    visited[i][j] = 1;
                }
                else if (square[i][j - 1])
                {
                    visited[i][j] = 1;
                    printf("%c", 'U');
                }
            
            }

        }
    }
    return 0;
}