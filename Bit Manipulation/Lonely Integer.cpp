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
    int N;
    int num, X, i;
    
    scanf("%d", &N);
    
    scanf("%d", &X);
    
    for(i = 0; i<N - 1; i++)
    {
        scanf("%d", &num);
        X ^= num;
    }
    
    printf("%d\n", X);
    
    return 0;
}
