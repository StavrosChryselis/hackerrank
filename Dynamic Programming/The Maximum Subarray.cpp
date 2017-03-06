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
#include <algorithm>
#include <limits.h>

using namespace std;

int N, maxval;
int A[100007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    maxval = INT_MIN;
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &A[i]);
        maxval=max(maxval, A[i]);
    }
}

inline void solve()
{
    int i, cont, sub, maxc;
    
    maxc = INT_MIN;
    
    if(maxval <= 0)
    {
        printf("%d %d\n", maxval, maxval);
        return;
    }
    
    for(i = 0; A[i] <= 0; i++);
    
    cont = sub = maxc = A[i];
    
    for(i++; i < N; i++)
    {
        if(A[i] > 0)
            sub += A[i];
        
        if(cont + A[i] >=0)
        {
            cont += A[i];
            maxc = max(maxc, cont);
        }
        
        else
            cont = 0;
    }
        
    printf("%d %d\n", maxc, sub);
    
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        {
        init();
        solve();
    }
    
    return 0;
}
