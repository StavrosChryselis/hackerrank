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

int s, t, a, b, N, M;

inline void init()
{
    scanf("%d %d %d %d %d %d", &s, &t, &a, &b, &N, &M);
}

inline void solve()
{
    int apples, oranges;
    
    apples = oranges = 0;
    
    int num;
    
    while(N--)
    {
        scanf("%d", &num);
        num = a + num;
        
        if(s <= num && num <= t)
            apples++;
    }
    
    while(M--)
    {
        scanf("%d", &num);
        num = b + num;
        
        if(s <= num && num <= t)
            oranges++;
    }
    
    printf("%d\n%d\n", apples, oranges);
}

int main()
{
    init();
    solve();
    
    return 0;
}
