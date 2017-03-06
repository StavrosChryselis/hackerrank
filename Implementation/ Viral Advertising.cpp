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

int N;

int main()
{
    int i, curr = 5, ans = 0;
    
    scanf("%d", &N);
    
    for(i = 1; i<=N; i++)
    {
        curr/=2;
        ans += curr;
        curr *=3;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
