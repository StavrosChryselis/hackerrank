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
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> A;
vector<pair<int, int> > medians;
int P, Q;
int N;

inline void init()
{
	int i, num, med;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		A.push_back(num);
	}

	scanf("%d %d", &P, &Q);

	A.push_back(-1000000007);
	A.push_back(2000000007);

	sort(A.begin(), A.end());
	
	for (i = 2; i < A.size() - 1 ; i++)
	{
		med = (A[i - 1] + A[i]) / 2;
		medians.push_back(make_pair(med, min(med - A[i - 1], A[i] - med)));
	}
}

inline int solve()
{
	int mval = -1, mmax;
	pair< vector<int>::iterator, vector<int>::iterator> pp, qq;
	vector<pair<int, int> > ::iterator kk, ee;
	
	if (P > Q)
		swap(P, Q);

	pp = equal_range(A.begin(), A.end(), P);
	qq = equal_range(A.begin(), A.end(), Q);

	if(pp.first == pp.second)
		pp.first--;

	if(qq.first == qq.second)
		qq.first--;

	if (abs(P - *(pp.first)) < abs(P - *(pp.second)))
	{
		mval = abs(P - *(pp.first));
		mmax = P;
	}

	else
	{
		mval = abs(P - *(pp.second));
		mmax = P;
	}
	
	if (abs(Q - *(qq.first)) < abs(Q - *(qq.second)))
	{
		if (abs(Q - *(qq.first)) > mval)
		{
			mval = abs(Q - *(qq.first));
			mmax = Q;
		}
	}

	else
	{
		if (abs(Q - *(qq.second)) > mval)
		{
			mval = abs(Q - *(qq.second));
			mmax = Q;
		}
	}

	for (kk = lower_bound(medians.begin(), medians.end(), make_pair(P, -1000000007)); kk != medians.end() && kk->first < Q; kk++)
		if (kk->second > mval)
		{
			mval = kk->second;
			mmax = kk->first;
		}

	return mmax;

}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	printf("%d\n", solve());

	return 0;
}
