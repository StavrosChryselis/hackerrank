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
int MEMO[1000007];
int N, K;

inline void init()
{
    scanf("%d %d", &N, &K);
    
    for(int i = 1; i<=N; i++)
    {
        scanf("%d", &A[i]);
        MEMO[A[i]] = i;
    }
}

inline void solve()
{
    int i;
    
    for(i = 1; i<=N && K; i++)
    {
        if(A[i] < N - i + 1)
        {
            MEMO[A[i]] = MEMO[N - i + 1];
            swap(A[i], A[MEMO[N - i + 1]]);
            MEMO[N - i + 1] = i;
            
            K--;
        }
    }
}

int main() {
    init();
    solve();
    
    for(int i = 1; i<=N; i++)
        printf("%d ", A[i]);
    return 0;
}
