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

int N, K;

inline void solve()
{
    int res = 0, num;
    
    scanf("%d %d", &N, &K);
    
    while(N--)
        {
        scanf("%d", &num);
        res ^= num;
    }
    
    if(res)
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
