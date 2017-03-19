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
#include <unordered_map>

#define MAXN 100007
using namespace std;

unordered_map<int, unordered_map<int, bool> > memo;
int N, K;
int x, y;
int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int xs[8];
int ys[8];
bool blocked[8];

inline void init()
{
	int a, b;

	cin >> N >> K;
	cin >> x >> y;

	while (K--)
	{
		cin >> a >> b;
		memo[a][b] = 1;
	}

}

inline bool is_blocked(int a, int b)
{
	if (a > N || b > N || a <= 0 || b <= 0)
		return 1;

	if (memo.find(a) == memo.end())
		return 0;

	if (memo[a].find(b) == memo[a].end())
		return 0;

	return 1;
}

inline void advance(int i)
{
	if (blocked[i])
		return;

	xs[i] += dx[i];
	ys[i] += dy[i];
	
	if(is_blocked(xs[i], ys[i]))
		blocked[i] = 1;
}

inline int coun()
{
	int i, rval = 0;

	for (i = 0; i < 8; i++)
		if (!blocked[i])
			rval++;

	return rval;
}

inline int solve()
{
	int rval = 0, temp;
	int i;

	for (i = 0; i < 8; i++)
	{
		xs[i] = x;
		ys[i] = y;
		advance(i);
		blocked[i] = is_blocked(xs[i], ys[i]);
	}

	temp = coun();

	while (temp)
	{
		rval += temp;

		for (i = 0; i < 8; i++)
			advance(i);
		temp = coun();
	}

	return rval;
}

int main()
{
	ios::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);

	init();
	cout << solve() << "\n";

	return 0;
}
