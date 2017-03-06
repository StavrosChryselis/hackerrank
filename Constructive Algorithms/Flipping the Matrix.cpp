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
#include <algorithm>
#include <vector>

using namespace std;

int N, NN;
vector< vector< int > > A, B, C, D;

inline void pre()
{
	int i;

	A.resize(260);
	B.resize(260);
	C.resize(260);
	D.resize(260);

	for (i = 0; i < 260; i++)
	{
		A[i].resize(260);
		B[i].resize(260);
		C[i].resize(260);
		D[i].resize(260);
	}
}

inline void init()
{
	int i, j;

	scanf("%d", &N);

	NN = 2 * N;

	for (i = 1; i <= NN; i++)
		for (j = 1; j <= NN; j++)
		{
			scanf("%d", &A[i][j]);
			D[i][j] = C[i][j] = B[i][j] = A[i][j];
		}
}

inline void hor(vector< vector< int > > &arr)
{
	int i, j;

	for (i = 1; i <= NN; i++)
		for (j = 1; j <= N; j++)
			swap(arr[i][j], arr[i][NN - j + 1]);
}

inline void ver(vector< vector< int > > &arr)
{
	int i, j;

	for (i = 1; i <= NN; i++)
		for (j = 1; j <= N; j++)
			swap(arr[j][i], arr[NN - j + 1][i]);

	arr[j][i] = arr[j][i];
}

inline int solve()
{
	int rval = 0;
	int i, j;

	hor(B);
	ver(C);
	hor(D);
	ver(D);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			rval += max(max(A[i][j], B[i][j]), max(C[i][j], D[i][j]));

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	pre();

	int T;

	scanf("%d", &T);

	while (T--)
	{
		init();
		printf("%d\n", solve());
	}

	return 0;
}
