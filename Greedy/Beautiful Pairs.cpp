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

int MEMO[1007];
int N;

inline int solve()
{
    int num;
    int i;
    int c = 0;
    
    scanf("%d", &N);    
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        MEMO[num]++;
    }
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        if(MEMO[num])
        {
            c++;
            MEMO[num]--;
        }
    }
    
    if(c < N)
        return c + 1;
    else
        return N - 1;
}

int main() 
{
    printf("%d\n", solve());
    
    return 0;
}
