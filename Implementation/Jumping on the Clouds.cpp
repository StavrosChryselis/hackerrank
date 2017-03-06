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

int N;
int A[128];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
}

inline int solve()
{
    int curr = 0, moves = 0;
    
    while(curr < N - 1)
    {
        moves++;
        if(!A[curr + 2])
            curr+= 2;
        else
            curr++;
    }
    
    return moves;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
