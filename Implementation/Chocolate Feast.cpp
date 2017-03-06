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

using namespace std;

inline int solve()
{
    int N, C, M;
    int chocs, wraps;
    
    scanf("%d %d %d", &N, &C, &M);
    
    chocs = wraps = N / C;
    
    while(wraps >= M)
    {
        chocs += wraps / M;
        wraps = wraps % M + wraps / M;
    }
    
    return chocs;    
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    
    return 0;
}
