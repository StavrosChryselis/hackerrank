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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int A[100007];
int DP[100007][2]; //0 = min, 1 = max
int N;

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
       scanf("%d", &A[i]);
}

inline int solve()
{
    int i;
    
    for(i = 1; i<N; i++)
    {
        DP[i][0] = max(abs(1 - A[i - 1]) + DP[i - 1][1], DP[i - 1][0]);
        DP[i][1] = max(abs(A[i] - 1) + DP[i - 1][0], abs(A[i] - A[i - 1]) + DP[i - 1][1]);
    }
    
    return max(DP[N - 1][0], DP[N - 1][1]);
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
