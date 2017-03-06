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
    int i, num, count = 0;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        
        if(num <= 0)
            count++;
    }
    
    if(count < K)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        solve();
    
    return 0;
}
