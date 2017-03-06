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

using namespace std;

int N, K;
int A[100007];

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    sort(A, A + N);
}

inline int solve()
{
    int i = 0;
    
    while(K - A[i] >= 0)
    {
        K -= A[i];
        i++;
    }
    
    return i;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
