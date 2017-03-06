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

int N;
int A[100007];


inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 1; i<=N; i++)
        scanf("%d", &A[i]);
}

inline int solve()
{
    int ans = 0, i;
    
    for(i = N; i>= 1; i--)
    {
        if((ans + A[i]) % 2)
            ans = (ans + A[i]) / 2 + 1;
        else
            ans = (ans + A[i]) / 2;     
    }
    
    return ans;
}
int main() 
{
    init();
    printf("%d\n", solve());
    return 0;
}
