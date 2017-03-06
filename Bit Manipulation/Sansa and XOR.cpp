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
int A[100007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N;i++)
        scanf("%d", &A[i]);
}

inline int solve()
{
    if(N % 2 == 0)
        return 0;
    
    int ans = 0;
    
    for(int i = 0; i<N; i+= 2)
        ans ^= A[i];
    
    return ans;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        {
        init();
        printf("%d\n", solve());
    }
    
    return 0;
}
