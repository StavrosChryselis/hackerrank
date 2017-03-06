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

int N, M;
int A[1000017];
int B[1000017];
int freqA[10007];
int freqB[10007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &A[i]);
        freqA[A[i]]++;
    }
    
    scanf("%d", &M);
    
    for(i = 0; i<M; i++)
    {
        scanf("%d", &B[i]);
        freqB[B[i]]++;
    }
}

inline void solve()
{
    int i;
    
    for(i = 0; i<10007; i++)
        if(freqB[i] > freqA[i])
            printf("%d ", i);
    
    puts("");
}

int main()
{
    init();
    solve();
    
    return 0;
}
