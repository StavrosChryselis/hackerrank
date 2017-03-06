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

long long DP[100007];
long long SUM[100007];
int N;
long long A[100007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
   
    for(i = 1; i<=N; i++)
        scanf("%lld", &A[i]);

    SUM[N + 1] = 0;
    
    for(i = N; i>= 1; i--)
        SUM[i] = SUM[i + 1] + A[i];
}

inline long long solve()
{
    int i;
    
    if(N <= 3)
        return SUM[N];
    
    
    DP[N] = SUM[N];
    DP[N - 1] = SUM[N - 1];
    DP[N - 2] = SUM[N - 2];
    
    for(i = N - 3; i>= 1; i--)
        DP[i] = SUM[i] - min(DP[i + 1], min(DP[i + 2], DP[i + 3]));
    
    return DP[1];
    
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        init();
        printf("%lld\n", solve());
    }
    
    return 0;
}
