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
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string A[100];
int N;

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        cin>>A[i];
        sort(A[i].begin(), A[i].end());
    }
}

inline bool check()
{
    int i, j;
    
    for(j = 0; j < N; j++)
        for(i = 1; i < N; i++)
            if(A[i][j] < A[i - 1][j])
                return 0;
    return 1;
}
int main() 
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        init();
        if(check())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
