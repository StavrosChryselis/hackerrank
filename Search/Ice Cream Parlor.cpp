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
#include <string.h>

using namespace std;

int MEMO[10007];
int N, V;

inline void solve()
{
    int i, num, ans1, ans2;
    
    scanf("%d %d", &V, &N);
    
    memset(MEMO, 0, sizeof(MEMO));
    
    for(i = 1; i<=N; i++)
    {
        scanf("%d", &num);
        
        if(num < V && MEMO[V - num])
        {
            ans1= MEMO[V-num];
            ans2 = i;
        }
        
        MEMO[num] = i;
    }
    
    printf("%d %d\n", ans1, ans2);
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        solve();
    
    return 0;
}
