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
    int i, j;
    
    for(i = 0; i<100; i++)
        if(A[i])
        {
            for(j = 0; j < A[i]; j++)
                printf("%d ", i);
        }
    
    puts("");
}

int main()
{
    solve();
    print();
    
    return 0;
}
