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
int A[1024];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &A[i]);
        A[i] %= 2;
    }
}

inline int solve()
{
    int ans = 0, i;
    
    for(i = 0; i<N - 1; i++)
    {
        if(A[i])
        {
            ans+= 2;
            A[i + 1] = !A[i + 1];
        }
    }
    
    if(A[N - 1])
        return -1;
    
    return ans;
}

int main()
{
    init();
    
    int ans = solve();
    
    if(ans == -1)
        printf("NO\n");
    else
        printf("%d\n", ans);
    
    return 0;
}
