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

long long num;

int main()
{
    int i;
    long long ans = 1;
    
    scanf("%lld", &num);
    
    while(num)
    {
        if(num % 2 == 0)
            ans *= 2;
        num /= 2;
    }
        
    printf("%lld\n", ans);
    
    return 0;
}
