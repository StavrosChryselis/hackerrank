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

inline void solve()
{
    int ans = 0;
    int i, num;
    
    scanf("%d", &N);
    scanf("%d", &num);
    
    for(i = 2; i<= N; i++)
    {
        scanf("%d", &num);
        if(num % 2)
            ans ^= i - 1;
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
