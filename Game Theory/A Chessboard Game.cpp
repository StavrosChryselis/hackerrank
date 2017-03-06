/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <stdio.h>
#include <string.h>

using namespace std;

int board[16][16];

bool check(int x, int y)
{
	if (x <= 0 || y <= 0)
		return 1;

	if (board[x][y] != -1)
		return board[x][y];

	if (check(x - 2, y + 1) == 0 || check(x - 2, y - 1) == 0 || check(x + 1, y - 2) == 0 || check(x - 1, y - 2) == 0)
		board[x][y] = 1;

	else
		board[x][y] = 0;

	return board[x][y];
}


int main()
{
	int T, f, s;

	memset(board, -1, sizeof(board));

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &f, &s);

		if (check(f, s))
			printf("First\n");
		else
			printf("Second\n");
	}

	return 0;
}
