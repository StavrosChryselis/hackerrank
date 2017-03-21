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
#include <string>

#define ll long long
using namespace std;

inline ll digit_sum(string &A)
{
	ll rval = 0;
	int i;

	for (i = 0; i < A.size(); i++)
		rval += A[i] - '0';

	return rval;
}

ll NUM;

inline void init()
{
	string S;
	ll k;

	cin >> S >> k;

	NUM = digit_sum(S) * k;
}

inline ll solve()
{
	while (NUM > 9)
	{
		string S = to_string(NUM);
		NUM = digit_sum(S);
	}

	return NUM;
}

int main()
{
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";

	return 0;
}
