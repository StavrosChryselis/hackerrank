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
#include <cstring>
#include <vector>
#include <algorithm>

#define SIEVE_N 100007
using namespace std;

bool is_prime[SIEVE_N];
vector< int > primes;
vector< pair<int, int> > A;

inline void sieve()
{
	int i, j;

	memset(is_prime, 1, sizeof(is_prime));

	primes.push_back(2);

	is_prime[0] = is_prime[1] = 0;

	for (i = 4; i < SIEVE_N; i += 2)
		is_prime[i] = 0;

	for (i = 3; i < SIEVE_N; i += 2)
		if (is_prime[i])
		{
			primes.push_back(i);
			for (j = i + i; j < SIEVE_N; j += i)
				is_prime[j] = 0;
		}

	//
	for (i = 0; i < primes.size(); i++)
		A.push_back(make_pair(primes[i], i + 1));
}

inline void solve()
{
	vector< pair<int, int> >::iterator ii;
	int i;
	int num;

	cin >> num;

	if(num == 1)
	{
		cout << "Bob\n";
		return;
	}

	ii = upper_bound(A.begin(), A.end(), make_pair(num, (int)A.size() + 1));

	if (ii == A.end())
	{
		cout << "Bob\n";
		return;
	}

	ii = prev(ii);

	if (ii->second % 2)
		cout << "Alice\n";

	else
		cout << "Bob\n";
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;

	cin >> T;

	sieve();

	while (T--)
		solve();

	return 0;
}
