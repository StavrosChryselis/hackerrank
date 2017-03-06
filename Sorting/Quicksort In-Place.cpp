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
#include <algorithm>

using namespace std;

int A[5007];
int N;

inline void init()
{
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
}

inline void print()
{
	int i;

	for (i = 0; i < N; i++)
		printf("%d ", A[i]);

	putchar('\n');
}

inline int partition(int lo, int hi)
{
	int pivot = A[hi];
	int i = lo;

	for (int j = lo; j < hi; j++)
		if (A[j] <= pivot)
		{
			swap(A[i], A[j]);
			i++;
		}
	swap(A[i], A[hi]);
	return i;
}

void quicksort(int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(lo, hi);
		print();
		quicksort(lo, p - 1);
		quicksort(p + 1, hi);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	quicksort(0, N - 1);

	return 0;
}
