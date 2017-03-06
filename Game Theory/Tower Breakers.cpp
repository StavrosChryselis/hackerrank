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

int N, M;

inline void init()
{
    scanf("%d %d", &N, &M);
}

inline int solve()
{
    if(M == 1)
        return 2;
    
    if(N % 2)
        return 1;
    return 2;
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
