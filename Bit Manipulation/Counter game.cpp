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

int setBits(unsigned long long int n) 
{
    int count = 0 ;
    while(n) 
    {
        n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int main() 
{
    int t ;
    scanf("%d\n",&t) ;
    while(t--) 
    {
        unsigned long long int n ;
        scanf("%llu\n",&n) ;
        if (setBits(n-1) & 1) 
          printf("Louise\n") ;
        else printf("Richard\n") ;
    }
    return 0;
}
