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
#include <string.h>

using namespace std;

int dp[2][2007];
int N, K;
int items[20007];

inline void init()
{
    scanf("%d %d", &N, &K);
    
    for(int i = 1; i<=N; i++)
        scanf("%d", &items[i]);
}

inline int solve()
{
    int i, j;
    
    memset(dp, 0, sizeof(dp));
    
  	for(j=1; j<=N; j++)
		for(i=1; i<=K; i++)
		{
			if(i-items[j]>=0)
				dp[j%2][i]=max(items[j]+dp[j%2][i-items[j]], dp[(j-1)%2][i]);
			else
				dp[j%2][i]=dp[(j-1)%2][i];
		}
    return dp[N % 2][K];
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        init();
        printf("%d\n", solve());
    }
    
    return 0;
}
