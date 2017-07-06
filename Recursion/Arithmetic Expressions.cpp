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
#include <vector>

#define MAXN 10007
using namespace std;

int N;
int A[MAXN];
vector<char> ans;

inline void init()
{
	int i;

	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];
}

bool solve(int curr, int pos)
{
	if (curr % 101 == 0)
		return 1;

	if (pos >= N)
		return 0;

	ans.push_back('+');
	if (solve(curr + A[pos], pos + 1))
		return 1;
	ans.pop_back();

	ans.push_back('-');
	if (solve(curr - A[pos], pos + 1))
		return 1;
	ans.pop_back();

	ans.push_back('*');
	if (solve(curr * A[pos], pos + 1))
		return 1;
	ans.pop_back();

	return 0;
}

void print()
{
	int i;

	cout << A[0];
	for (i = 1; i < N; i++)
	{
		if (i - 1 < ans.size())
			cout << ans[i - 1];
		else
			cout << "*";
		cout << A[i];
	}
	cout << "\n";
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	solve(A[0], 1);
	print();

	return 0;
}
