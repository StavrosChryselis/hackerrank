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

int A[100007];
int N;

inline void init()
{
    scanf("%d", &N);
    
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    sort(A, A + N);
    
}

inline int solve()
{
    int t = A[0] + 4;
    int c = 1;
    
    for(int i = 1; i<N; i++)
        if(A[i] > t)
        {
            c++;
            t = A[i] + 4;
    }
    
    return c;
}

int main() {
   init();
    printf("%d\n", solve());
    return 0;
}
