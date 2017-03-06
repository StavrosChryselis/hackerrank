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

int A[100];
int N;

inline void solve()
{
    int num;
    
    scanf("%d", &N);
    
    while(N--)
    {
        scanf("%d", &num);
        A[num]++;
    }
}

inline void print()
{
    int i;
    
    for(i = 0; i<100; i++)
        printf("%d ", A[i]);
    
    puts("");
}

int main()
{
    solve();
    print();
    
    return 0;
}
