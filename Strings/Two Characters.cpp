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
#include <ctype.h>
#include <algorithm>

#define gc() getchar()
using namespace std;

int N;
string A;

inline void getstring(string &A)
{
	char c = gc();

	while (isspace(c))
		c = gc();

	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}

inline void extract(char a, char b, string &targ)
{
	int i;

	targ.clear();

	for (i = 0; i < N; i++)
		if (A[i] == a || A[i] == b)
			targ.push_back(A[i]);
}

inline bool check(string &t)
{
	int i;

	for (i = 1; i < t.length(); i++)
		if (t[i] == t[i - 1])
			return 0;

	return 1;
}

inline int solve()
{
	int rval = 0;
	char a, b;
	string t;

	for (a = 'a'; a < 'z'; a++)
		for (b = a + 1; b <= 'z'; b++)
		{
			extract(a, b, t);
			if (check(t))
				rval = max(rval, (int)t.length());
		}

	if (rval == 1)
		return 0;

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	getstring(A);

	printf("%d\n", solve());

	return 0;
}
