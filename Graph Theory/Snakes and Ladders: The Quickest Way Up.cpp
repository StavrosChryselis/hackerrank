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
#include <deque>
#include <string.h>
#include <vector>

using namespace std;

bool V[101];
int gate[101];

inline void init()
{
	int N, f, s;

	memset(V, 0, sizeof(V));
	memset(gate, 0, sizeof(gate));

	scanf("%d", &N);

	while (N--)
	{
		scanf("%d %d", &f, &s);
		gate[f] = s;
	}

	scanf("%d", &N);

	while (N--)
	{
		scanf("%d %d", &f, &s);
		gate[f] = s;
	}
}

inline int solve()
{
	deque< pair<int, int> > Q; //pos, moves
	pair<int, int> curr;
	int i;

	Q.push_back(make_pair(1, 0));

	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();

		if (gate[curr.first])
			curr.first = gate[curr.first];


		if (curr.first == 100)
			return curr.second;

		V[curr.first] = 1;

		for (i = 1; curr.first + i <= 100 && i <= 6; i++)
			if (!V[curr.first + i])
			{
				V[curr.first + i] = 1;
				Q.push_back(make_pair(curr.first + i, curr.second + 1));
			}
	}

	return -1;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--)
	{
		init();
		printf("%d\n", solve());
	}

	return 0;
}
