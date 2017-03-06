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

inline int solve()
{
    int count = 0;

    
    scanf("%d", &N);
        int temp = N;
    while(N)
    {
        if(N % 10 != 0 && temp % (N % 10) == 0)
            count++;
        N /= 10;
    }
    
    return count;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    
    return 0;
}
