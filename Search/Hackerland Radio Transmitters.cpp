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

#define MAXN 100007
using namespace std;

int N, K;
int A[MAXN];

inline void init()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);
}

inline int solve()
{
	int rval = 0;
	int i, j;

	i = 0;
	j = 0;

	while (j < N)
	{
		if (A[j] - A[i] <= K && A[j + 1] - A[i] > K)
		{
			rval++;
			i = j;
			while (A[j] - A[i] <= K)
				j++;
			i = j;
		}

		else if (A[j] - A[i] > K)
		{
			rval++;
			i = j;
		}

		if (A[N - 1] - A[j] <= K)
			return rval + 1;
		j++;
	}

	return rval;
}

int main()
{
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";

	return 0;
}
