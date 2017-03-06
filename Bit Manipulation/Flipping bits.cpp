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

#define A 4294967295

int main()
{
    int N, i;
    long long a;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%lld", &a);
        printf("%lld\n", A - a);
    }
    
    return 0;
}
