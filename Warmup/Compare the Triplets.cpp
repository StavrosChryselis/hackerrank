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

int a0, a1, a2, b0, b1, b2;
int s1, s2;

inline void init()
{
    scanf("%d %d %d", &a0, &a1, &a2);
    scanf("%d %d %d", &b0, &b1, &b2);
}

inline void solve()
{
    if(a0 > b0)
        s1++;
    else if(a0 < b0)
        s2++;
    
    if(a1 > b1)
        s1++;
    else if(a1 < b1)
        s2++;
        
    if(a2 > b2)
        s1++;
    else if(a2 < b2)
        s2++;
}

int main()
{
    init();
    solve();
    printf("%d %d\n", s1, s2);
    
    return 0;
}
