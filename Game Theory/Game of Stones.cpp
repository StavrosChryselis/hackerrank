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

bool DP[128];

inline void init()
{
    DP[2] = DP[3] = DP[5] = 1;
    DP[4] = 1;
    
    for(int i = 6; i<=100; i++)
        if(DP[i - 2] == 0 || DP[i - 3] == 0 || DP[i - 5] == 0)
            DP[i] = 1;
}

int main() 
{
    int T, num;
    
    init();
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d", &num);
        if(DP[num])
            printf("First\n");
        else
            printf("Second\n");
    }
    return 0;
}
