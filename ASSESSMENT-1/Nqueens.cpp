#include <iostream>
#define N 4
using namespace std;


void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}


bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}


bool solveNQUtil(int board[N][N], int col)
{
	
	if (col >= N)
		return true;

	// Consider this column and try placing
	// this queen in all rows one by one
	for (int i = 0; i < N; i++) {
		
		// Check if the queen can be placed on
		// board[i][col]
		if (isSafe(board, i, col)) {
			
			// Place this queen in board[i][col]
			board[i][col] = 1;

			// recur to place rest of the queens
			if (solveNQUtil(board, col + 1))
				return true;

			// If placing queen in board[i][col]
			// doesn't lead to a solution, then
			// remove queen from board[i][col]
			board[i][col] = 0; // BACKTRACK
		}
	}

	// If the queen cannot be placed in any row in
	// this column col then return false
	return false;
}

bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}


int main()
{
	solveNQ();
	return 0;
}

