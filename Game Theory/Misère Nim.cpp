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
    bool flag = 0;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d",&num);
        ans ^= num;
        if(num > 1)
            flag = 1;
    }
    
    if(flag && !ans || !flag && ans == 1)
        printf("Second\n");
    else
        printf("First\n");
}

int main() 
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        solve();
    return 0;
}
