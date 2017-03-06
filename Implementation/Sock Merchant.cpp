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
int memo[101];

inline void init()
{
    int i, num;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        memo[num]++;
    }
}

inline int solve()
{
    int rval = 0, i;
    
    for(i = 1; i<=100; i++)
        rval += memo[i] / 2;
    
    return rval;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
