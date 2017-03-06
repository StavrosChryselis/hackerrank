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

int N;

inline int solve()
{
    int curr = 1, i;
    
    scanf("%d", &N);
    for(i = 1; i<=N; i++)
    {
        if(i%2)
            curr *= 2;
        else
            curr++;
    }
    
    return curr;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    
    return 0;
}
