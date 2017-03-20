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

#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 128
using namespace std;

int A[128], B[128];
int N;

inline void init()
{
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));

	int i, j, num;

	cin >> N;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			cin >> num;
			A[i] += num;
			B[j] += num;
		}

	sort(A, A + N);
	sort(B, B + N);
}

inline bool solve()
{
	int i;

	for (i = 0; i < N; i++)
		if (A[i] != B[i])
			return 0;

	return 1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;

	cin >> T;

	while (T--)
	{
		init();
		if (solve())
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}

	return 0;
}
