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

#define MAXN 16
#define MAXVAL 128
using namespace std;

int N, M;
int A[MAXN], B[MAXN];

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &M);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    for(i = 0; i<M; i++)
        scanf("%d", &B[i]);
}

inline bool checkA(int num)
{
    int i;
    
    for(i = 0; i<N; i++)
        if(num % A[i])
            return 0;
    
    return 1;
}

inline bool checkB(int num)
{
    int i;
    
    for(i = 0; i<M; i++)
        if(B[i] % num)
            return 0;
    
    return 1;
}

inline int solve()
{
    int rval = 0, i;
    
    for(i = 1; i<=MAXVAL; i++)
        if(checkA(i) && checkB(i))
            rval++;
        
    return rval;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
