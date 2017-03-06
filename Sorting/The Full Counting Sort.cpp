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
#include <iostream>
#include <vector>

using namespace std;

vector<string> A[100];
int N, K;

inline void init()
{
	int i, num;
	string S;

	cin >> N;
	K = N / 2;

	for (i = 0; i < K; i++)
	{
		cin >> num >> S;
		A[num].push_back("-");
	}

	for (; i < N; i++)
	{
		cin >> num >> S;
		A[num].push_back(S);
	}
}

inline void print()
{
	int i, j;

	for (i = 0; i < 100; i++)
		if (!A[i].empty())
			for (j = 0; j < A[i].size(); j++)
				cout << A[i][j] << " ";
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	print();

	return 0;
}
