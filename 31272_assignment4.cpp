#include <iostream>
#include <string.h>
using namespace std;
#define N 8

void printSol(int board[N][N])
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
};

bool isSafe(int row, int col, int slash[N][N], int backslash[N][N], bool rowcov[N], bool slashcov[2 * N - 1], bool backslashcov[2 * N - 1])
{
    if (rowcov[row] || slashcov[slash[row][col]] || backslashcov[backslash[row][col]])
    {
        return false;
    }
    return true;
}

bool solveNQfun(int board[N][N], int col, int slash[N][N], int backslash[N][N], bool rowcov[N], bool slashcov[2 * N - 1], bool backslashcov[2 * N - 1])
{
    if (col >= N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, slash, backslash, rowcov, slashcov, backslashcov))
        {
            board[i][col] = 1;
            rowcov[i] = true;
            slashcov[slash[i][col]] = true;
            backslashcov[backslash[i][col]] = true;

            if (solveNQfun(board, col + 1, slash, backslash, rowcov, slashcov, backslashcov))
            {
                return true;
            }

            board[i][col] = 0;
            rowcov[i] = false;
            slashcov[slash[i][col]] = false;
            backslashcov[backslash[i][col]] = false;
        }
    }
    return false;
}

bool solveNQ()
{
    int board[N][N];
    memset(board, 0, sizeof board);

    int slash[N][N];
    int backslash[N][N];

    bool rowcov[N] = {false};

    bool slashcov[2 * N - 1] = {false};
    bool backslashcov[2 * N - 1] = {false};

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            slash[r][c] = r + c;
            backslash[r][c] = r - c + (N - 1);
        }
    }

    cout << "enter starting col in row 0 :";
    int s;
    cin >> s;

    if (solveNQfun(board, s, slash, backslash, rowcov, slashcov, backslashcov) == false)
    {
        cout << "solution doesn't exists" << endl;
        return false;
    }

    printSol(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}