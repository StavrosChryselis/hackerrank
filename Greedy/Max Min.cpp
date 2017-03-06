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
#include <limits.h>

using namespace std;

int N, K;
int A[100007];

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    sort(A, A + N);
}

inline int solve()
{
    int i, j;
    int MIN = INT_MAX;
    
    for(i = K - 1, j = 0; i < N; i++, j++)
        MIN = min(MIN, A[i] - A[j]);
    
    return MIN;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
