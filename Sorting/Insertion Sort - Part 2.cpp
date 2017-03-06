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
int A[1007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
}

inline void print()
{
    int i;
    
    for(i = 0; i<N; i++)
        printf("%d ", A[i]);
    
    putchar('\n');
}

inline void fix(int pos)
{
    int i;
    
    int num = A[pos];
    
    for(i = pos - 1; A[i] > num && i >= 0; i--)
        A[i + 1] = A[i];
    
    A[i+1] = num;
}

inline void solve()
{
    int i;
    
    for(i = 1; i<N; i++)
    {
        fix(i);
        print();
    }
}

int main()
{
    init();
    solve();
    
    return 0;
}
