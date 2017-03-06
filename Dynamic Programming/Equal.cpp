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

int A[10007], B[10007];
int N, MIN;

inline void init()
{
    int i;
    
    MIN = 1010;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &A[i]);
        B[i] = A[i];
        MIN = min(MIN, A[i]);
    }
}

inline long long solve()
{
    long long sum = 0, sum2 = 0;
    int i;
    
    for(i = 0; i<N; i++)
    {
//        A[i] -= MIN;
        sum += A[i] / 5;
        A[i] %= 5;
        sum += A[i] / 2;
        A[i] %= 2;
        sum += A[i];
    }
    
    for(i = 0; i< N; i++)
    {
        B[i] -= MIN;
        sum2+= B[i] / 5;
        B[i] %= 5;
        sum2 += B[i] / 2;
        B[i] %= 2;
        sum2 += B[i];
    }
    return min(sum, sum2);
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        {
        init();
        printf("%lld\n", solve());
    }
    
    return 0;
}
