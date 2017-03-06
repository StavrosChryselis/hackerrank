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
    int N, i, num, S;
    
    scanf("%d %d", &S, &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        if(num == S)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    
    return 0;
}
