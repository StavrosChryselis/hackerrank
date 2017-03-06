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
int A[1007];

inline void init()
{
    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);
}

inline int solve()
{
    int c = 0, i, j;
    
    for(i = 0; i<N - 1; i++)
        for(j = i + 1; j<N; j++)
            if(A[i] > A[j])
                c++;
        
        return c;
}

int main()
{
    init();
    printf("%d\n", solve());
    return 0;
}
