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
#include <algorithm>

using namespace std;

inline void solve()
{
    int N;
    int f, i;
    
    scanf("%d", &N);
    
    f = N / 3 * 3;
    
    while((N - f) % 5 != 0 && f >= 0)
        f-= 3;
    
    if(f < 0 && N % 3)
    {
        printf("-1\n");
        return;
    }
    
  
    for(i = 0; i<f; i++)
        putchar('5');
    
    for(; i < N; i++)
        putchar('3');
    
    putchar('\n');
       
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        solve();
    
    return 0;
}
