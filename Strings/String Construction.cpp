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
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

bool MEMO[26];
string S;

inline void init()
{
    cin>>S;
    memset(MEMO, 0, sizeof(MEMO));
}

inline int solve()
{
    int i, ans = 0;
    
    for(i = 0; i<S.size(); i++)
        if(!MEMO[S[i] - 'a'])
        {
            ans++;
            MEMO[S[i] - 'a'] = 1;
        }
    
    return ans;
            
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        init();
        printf("%d\n", solve());
    }
    
    return 0;
}
