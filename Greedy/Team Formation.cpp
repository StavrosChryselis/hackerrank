#include <stdio.h>
#include <algorithm>
#include <set>
#include <limits.h>

using namespace std;

int N;
int A[100007];

inline void init()
{
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	sort(A, A + N);
}


inline int solve()
{
	multiset<pair<int, int> > Q; //skill, len
	int i, ans = INT_MAX;

	if (N == 0)
		return 0;

	for (i = 0; i < N; i++)
	{
		if (Q.empty())
			Q.insert(make_pair(A[i], 1));

		else
		{
			while (!Q.empty() && Q.begin()->first < A[i] - 1)
			{
				ans = min(ans, Q.begin()->second);
				if (ans == 1)
					return 1;

				Q.erase(Q.begin());
			}

			if (Q.empty() || Q.begin()->first == A[i])
				Q.insert(make_pair(A[i], 1));
			else
			{
				pair<int, int> temp = *Q.begin();
				Q.erase(Q.begin());
				temp.first++;
				temp.second++;
				Q.insert(temp);
			}
		}
	}

	while (!Q.empty())
	{
		ans = min(ans, Q.begin()->second);
		Q.erase(Q.begin());
	}

	return ans;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	while (T--)
	{
		init();
		printf("%d\n", solve());
	}

	return 0;
}
