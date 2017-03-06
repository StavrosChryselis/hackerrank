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

inline void solve()
{
    int i, num, N, ans = 0;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d",&num);
        ans ^= num;
    }
    
    if(ans)
        printf("First\n");
    else
        printf("Second\n");
}

int main() 
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        solve();
    return 0;
}
