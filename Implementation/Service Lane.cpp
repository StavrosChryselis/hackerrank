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

int A[100007][4];
int N, Q;

inline void init()
{
    int i, num;
    
    scanf("%d %d", &N, &Q);
    
    A[0][1] = A[0][2] = A[0][3] = 0;
    
    for(i = 1; i<=N; i++)
    {
        scanf("%d", &num);
        A[i][1] = A[i-1][1];
        A[i][2] = A[i-1][2];
        A[i][3] = A[i-1][3];
        A[i][num]++;        
    }
}

inline int solve()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    a++;
    b++;
    
    if(A[b][1] - A[a - 1][1])
        return 1;
    
    if(A[b][2] - A[a-1][2])
        return 2;
    
    return 3;    
}

int main()
{
    int i;
    
    init();

    for(i = 0; i<Q; i++)
        printf("%d\n", solve());
    
    return 0;
}
