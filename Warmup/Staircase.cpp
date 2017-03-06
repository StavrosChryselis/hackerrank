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

int main()
{
    int N, i, j;
    
    scanf("%d", &N);
    
    for(i = 1; i<=N; i++)
    {
        for(j = 1; j<= N - i; j++)
          putchar(' ');
        for(j = 1; j<=i; j++)
           putchar('#');
        putchar('\n');
    }
    
    return 0;
}
