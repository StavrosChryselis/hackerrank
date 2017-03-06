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
#include <vector>
#include <string.h>

using namespace std;

int gr[51];
bool a[51];

void partition(vector<int> &nums, int left)
{
	int i;

	if (left == 0)
	{
		int rval = 0;

		for (i = 0; i < nums.size(); i++)
			rval ^= gr[nums[i]];

		a[rval] = 1;
		return;
	}

	int start;

	if (nums.empty())
		start = 1;
	else
		start = nums.back() + 1;


	for (i = start; i + i + 1 <= left; i++)
	{
		nums.push_back(i);
		partition(nums, left - i);
		nums.pop_back();
	}

	if (!nums.empty())
	{
		nums.push_back(left);
		partition(nums, 0);
		nums.pop_back();
		return;
	}
}

inline void pre()
{
	int i, j;
	vector<int> temp;

	gr[1] = gr[2] = 0;

	for (i = 3; i <= 50; i++)
	{
		memset(a, 0, sizeof(a));
		partition(temp, i);

		for (j = 0; j <= 50; j++)
			if (!a[j])
			{
				gr[i] = j;
				break;
			}
	}
}

inline int solve()
{
	int N, num, rval = 0;

	scanf("%d", &N);

	while (N--)
	{
		scanf("%d", &num);
		rval ^= gr[num];
	}

	return rval;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	pre();

	scanf("%d", &T);

	while (T--)
	{
		if (solve())
			printf("ALICE\n");
		else
			printf("BOB\n");
	}

	return 0;
}
