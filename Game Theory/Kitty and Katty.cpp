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
    int T, N;
    
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d", &N);
        
        if(N == 1)
            printf("Kitty\n");        
        else if(N % 2)
            printf("Katty\n");
        else
            printf("Kitty\n");
    }
    
    return 0;
}
