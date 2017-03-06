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
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

string A, B;
int MEMO[26];

inline void init()
{
    cin>>A;
    cin>>B;
    memset(MEMO, 0, sizeof(MEMO));
}

inline bool solve()
{
    int i;
    
    for(i = 0; i<A.length(); i++)
        MEMO[A[i] - 'a'] = 1;
    
    for(i = 0; i<B.length(); i++)
        if(MEMO[B[i] - 'a'])
            return 1;
   
        return 0;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        {
        init();
        if(solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
