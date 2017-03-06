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
    long long c = 3, num;
    
    scanf("%lld", &num);
    
    while(num > c)
    {
        num -= c;
        c *= 2;
    }
    
    printf("%lld\n", c - num + 1);
    
    return 0;
}
