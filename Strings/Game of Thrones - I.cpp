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
#include <iostream>

using namespace std;

string S;
int MEMO[26];

inline void solve()
{
    int i;

    cin>>S;
    
    for(i = 0; i<S.size(); i++)
        MEMO[S[i] - 'a']++;
    
    if(S.size() % 2 == 0)
    {
        for(i = 0; i< 26; i++)
            if(MEMO[i] % 2)
            {
                printf("NO\n");
                return;
            }
        printf("YES\n");
    }
    
    else
    {
        int count = 0;
        
        for(i = 0; i<26; i++)
            count += MEMO[i] % 2;
        
        if(count == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
        
}

int main()
{
    solve();
    return 0;
}
