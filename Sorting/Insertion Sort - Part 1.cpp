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

int A[1007];
int N;

inline void print()
{
    int i;
    
    for(i = 0; i<N; i++)
        printf("%d ", A[i]);
    
    putchar('\n');
}

int main()
{
    int i, num;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    num = A[N - 1];
    
    for(i = N - 2; A[i]> num; i--)
    {
        A[i + 1] = A[i];
        print();
    }
    
    A[i + 1] = num;
    print();
    
    return 0;
}
