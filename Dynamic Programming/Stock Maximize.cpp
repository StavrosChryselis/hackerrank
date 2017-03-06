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

int A[50007];
int N;

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
}

inline long long solve()
{
    long long profit = 0;
    int i, MAX;
    
    MAX = A[N - 1];
    
    for(i = N - 2; i >= 0; i--)
    {
        if(A[i] < MAX)
            profit += MAX - A[i];
        else if(A[i] > MAX)
            MAX = A[i];            
    }
    
    return profit;
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
