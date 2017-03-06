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
#include <string>

using namespace std;

long long A, B;

inline void init()
{
	scanf("%lld %lld", &A, &B);
}

inline bool check(long long a)
{
	long long sq = a * a;
	string f, s;
	long long ff, ss;
	int i;

	string S = to_string(sq);

	for (i = 0; i < S.size() / 2; i++)
		f.push_back(S[i]);
	for (; i < S.size(); i++)
		s.push_back(S[i]);

	if (f.size() != 0)
		ff = stol(f);
	else
		ff = 0;
	ss = stol(s);

	return ff + ss == a;
}

inline void solve()
{
	long long i;
	bool flag = 0;

	for (i = A; i <= B; i++)
		if (check(i))
		{
			printf("%lld ", i);
			flag = 1;
		}

	if (flag == 0)
	{
		printf("INVALID RANGE\n");
		return;
	}
}

int main()
{
	init();
	solve();

	return 0;
}
