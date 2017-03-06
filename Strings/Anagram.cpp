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

string S;

inline int solve()
{
    int i;
    int memoA[26], memoB[26];
    
    memset(memoA, 0, sizeof(memoA));
    memset(memoB, 0, sizeof(memoB));
    
    cin>>S;

    if(S.size() % 2)
        return -1;
    
    for(i = 0; i<S.size() / 2; i++)
        memoA[S[i] - 'a']++;
    
    for(i = S.size() / 2; i < S.size(); i++)
        memoB[S[i] - 'a']++;
    
    int ans = 0;
    
    for(i = 0; i<26; i++)
        if(memoB[i] > memoA[i])
            ans += memoB[i] - memoA[i];
        
    return ans;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    
    return 0;
}
