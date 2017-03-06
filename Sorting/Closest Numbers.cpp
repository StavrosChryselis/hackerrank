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

int N;
int A[200007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    sort(A, A + N);
}

inline int diff(int a, int b)
{
    if(a > b)
        return a - b;
    return b - a;
}

inline void solve()
{
    int MIN = diff(A[0], A[1]);
    int i;
    
    for(i = 1; i< N - 1; i++)
        MIN = min(MIN, diff(A[i], A[i + 1]));
    
    for(i = 0; i< N - 1; i++)
        if(diff(A[i], A[i + 1]) == MIN)
            printf("%d %d ", A[i], A[i + 1]);
    
    putchar('\n');
}

int main()
{
    init();
    solve();
    
    return 0;
}
