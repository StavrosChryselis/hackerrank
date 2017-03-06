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
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

string S;
int N, M;
char A[10][10];

inline void init()
{
    cin>>S;
    N = floor(sqrt(S.size()));
    M = ceil(sqrt(S.size()));
    
    if(N * M < S.size())
        N++;
}

inline void solve()
{
    int i, j;
    
    for(i = 0; i<S.size(); i++)
        A[i / M][i % M] = S[i];
    
    for(i = 0; i<M; i++)
    {
        for(j = 0; j<N; j++)
            if(A[j][i] != 0)
                putchar(A[j][i]);
        putchar(' ');
    }
}

int main()
{
    init();
    solve();
    
    return 0;
}
