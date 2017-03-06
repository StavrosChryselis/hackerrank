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

int A[100007];
int N, M;

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &M);
    
    for(i = 0; i<M; i++)
        scanf("%d", &A[i]);
    
    sort(A, A + M);
}

inline int solve()
{
    int ans = max(A[0], N - 1 - A[M - 1]),i;
    
    for(i = 1; i<M; i++)
        ans = max(ans, (A[i] - A[i - 1]) / 2);
    
    return ans;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
