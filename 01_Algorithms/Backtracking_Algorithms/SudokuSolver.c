#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

// Check whether Putting a Number is Safe.
bool isSafe(int suduko[9][9], int x, int y, int value)
{
    for (int i = 0; i < 9; i++)
    {
        // Checking for Row
        if (suduko[x][i] == value)
        {
            return false;
        }
        
        // Checking for Coloum
        if (suduko[i][y] == value)
        {
            return false;
        }

        // Check for 3*3 Grid
        if (suduko[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == value)
        {
            return false;
        }
    }

    return true;
}

// Function to Solve the Suduko
bool solve(int suduko[9][9])
{
    // Traversing the Suduko
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            // Checking if Value is Empty
            if (suduko[i][j] == 0)
            {
                printf("Trying to Solve value at index[i] %d and index[j]  %d\n", i, j);

                // Loop for Trying Numbers
                for (int k = 1; k <= 9; k++)
                {
                    // Check if valid number
                    if (isSafe(suduko, i, j, k))
                    {
                        printf("Found a Possible Solution for index [%d] index [%d] \n ", i, j);
                        suduko[i][j] = k;

                        // Recursive Call
                        bool moreSolutions = solve(suduko);

                        if (moreSolutions)
                        {
                            return true;
                        }

                        else
                        {
                            // Backtracking
                            suduko[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSuduko(int suduko[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d \t", suduko[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // int row = sizeof(square);
    // int row2 = sizeof(square) / sizeof(int) / 5;
    // printf("%d \n", row);
    // printf("%d \n", row2);

    int suduko[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int suduko2[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                         {5, 2, 9, 1, 3, 4, 7, 6, 8},
                         {4, 8, 7, 6, 2, 9, 5, 3, 1},
                         {2, 6, 3, 0, 1, 5, 9, 8, 7},
                         {9, 7, 4, 8, 6, 0, 1, 2, 5},
                         {8, 5, 1, 7, 9, 2, 6, 4, 3},
                         {1, 3, 8, 0, 4, 7, 2, 0, 6},
                         {6, 9, 2, 3, 5, 1, 8, 7, 4},
                         {7, 4, 5, 0, 8, 6, 3, 1, 0}};

    // solved suduko 
    // 3 1 6 5 7 8 4 9 2 
    // 5 2 9 1 3 4 7 6 8 
    // 4 8 7 6 2 9 5 3 1 
    // 2 6 3 4 1 5 9 8 7
    // 9 7 4 8 6 3 1 2 5
    // 8 5 1 7 9 2 6 4 3
    // 1 3 8 9 4 7 2 5 6
    // 6 9 2 3 5 1 8 7 4
    // 7 4 5 2 8 6 3 1 9
    
    /*
    int visited[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},

                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},

                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    */

    solve(suduko);
    // solve(suduko2);

    // Printing the Solved the Suduko
    printSuduko(suduko);
}