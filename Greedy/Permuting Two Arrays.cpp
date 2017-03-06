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
#include <functional>

using namespace std;

int N, K;
int A[1007], B[1007];

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    for(i = 0; i<N; i++)
        scanf("%d", &B[i]);
    
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    
}

inline bool solve()
{
    int i;
    
    for(i = 0; i<N; i++)
        if(A[i] + B[i] < K)
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
        if(solve())
            printf("YES\n");
        else
            printf("NO\n");
        
    }
    
    return 0;
}
