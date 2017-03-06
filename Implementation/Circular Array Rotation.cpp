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

int N, K, Q;
int A[100007];

inline void init()
{
    int i;
    
    scanf("%d %d %d", &N, &K, &Q);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    K %= N;
}

int main()
{
    int num;
    
    init();
    
    while(Q--)
    {
        scanf("%d", &num);
        
        if(num - K >= 0)
            printf("%d\n", A[num - K]);
        else
            printf("%d\n", A[num - K + N]);
    }
    
    return 0;
}
