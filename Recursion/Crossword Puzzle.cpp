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
#include <cctype>
#include <vector>

#define gc() getchar()
using namespace std;

inline bool getstring(string &S)
{
	S.clear();

	char c = gc();

	while (!isalpha(c))
		c = gc();

	while (c != ';' && c != EOF)
	{
		S.push_back(c);
		c = gc();
	}

	if (c == EOF)
		return 0;

	return 1;
}

vector <string> board;
vector <string> A;

inline void init()
{
	int i, j;

	board.resize(15);
	board[0].resize(15);

	for (i = 1; i <= 10; i++)
	{
		board[i].resize(15);

		for (j = 1; j <= 10; j++)
			board[i][j] = gc();

		gc();
	}

	board[i].resize(15);

	string S;

	while (getstring(S))
		A.push_back(S);

	A.push_back(S);
}

inline bool can_fit(vector<string> &B, string &S, int i, int j, bool hor)
{
	int c;

	if (hor)
	{
		c = 0;
		while (c < S.size() && (B[i][j + c] == '-' || B[i][j + c] == S[c]))
			c++;

		if (c == S.size())
			return 1;

		return 0;
	}

	else
	{
		c = 0;
		while (c < S.size() && (B[i + c][j] == '-' || B[i + c][j] == S[c]))
			c++;

		if (c == S.size())
			return 1;

		return 0;
	}

	return 0;
}

inline void place_string(vector<string> &B, string &S, int i, int j, bool hor)
{
	int c;

	if (hor)
		for (c = 0; c < S.size(); c++)
			B[i][j + c] = S[c];

	else
		for (c = 0; c < S.size(); c++)
			B[i + c][j] = S[c];
}

inline bool check(vector<string> &B)
{
	int i, j;

	for (i = 1; i <= 10; i++)
		for (j = 1; j <= 10; j++)
			if (B[i][j] == '-')
				return 0;

	return 1;
}

inline void print(vector<string> &B)
{
	int i, j;

	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= 10; j++)
			cout << B[i][j];
		cout << "\n";
	}
}

bool f(vector<string> B, vector<string> STR)
{
	vector<string> BB, SSTR;
	int i, j, k;

	for (i = 1; i <= 10; i++)
		for (j = 1; j <= 10; j++)
			if (B[i][j] == '-')
			{
				for (k = 0; k < STR.size(); k++)
				{
					if (can_fit(B, STR[k], i, j, 1))
					{
						BB = B;
						SSTR = STR;
						place_string(BB, STR[k], i, j, 1);

						if (check(BB))
						{
							print(BB);
							return 1;
						}

						SSTR.erase(SSTR.begin() + k);
						if (f(BB, SSTR))
							return 1;
					}

					else if (can_fit(B, STR[k], i, j, 0))
					{
						BB = B;
						SSTR = STR;
						place_string(BB, STR[k], i, j, 0);

						if (check(BB))
						{
							print(BB);
							return 1;
						}

						SSTR.erase(SSTR.begin() + k);
						if (f(BB, SSTR))
							return 1;
					}
				}
			}

	return 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	f(board, A);

	return 0;
}
