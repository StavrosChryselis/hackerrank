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
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
 
using namespace std;
 
unsigned long long tree[1007];
int A[1007];
int N;
 
inline void update(int pos, int val)
{
	for( ; pos <= N; pos += pos & (-pos))
		tree[pos] += val;
}
 
inline unsigned long long query(int pos)
{
	unsigned long long sum = 0;
 
	for( ; pos > 0; pos -= pos & (-pos))
		sum += tree[pos];
 
	return sum;
}
 
void init()
{
	int i;
 
	memset(tree, 0, sizeof(tree));
 
	scanf("%d", &N);
 
	for(i=0; i<N; i++)
		scanf("%d", &A[i]);
 
}
 
int main()
{
	int i, T;
	unsigned long long sum = 0;
  
	scanf("%d", &T);
 
	while(T--)
	{
		init();
		sum=0;
		for(i = N-1; i >= 0; i--)
		{
			update(A[i] + 1, 1);
			sum += query(A[i]);
		}
        
        if(sum % 2 == 0)
		  printf("YES\n");
        else
          printf("NO\n");
	}
 
	return 0;
} 
