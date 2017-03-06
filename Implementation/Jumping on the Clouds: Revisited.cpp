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

int N, K;
int A[30];
int E = 100;

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
}

inline int solve()
{
 int   curr = K % N;
    
    while(curr != 0)
    {
        E--;
        if(A[curr])
            E -= 2;
        curr += K;
        if(curr >=N)
            curr -= N;
    }
    
    E--;
    if(A[0])
        E-= 2;
    
    return E;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
