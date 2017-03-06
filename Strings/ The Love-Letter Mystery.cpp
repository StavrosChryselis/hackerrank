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

#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

string S;

inline int solve()
{
    int i, c = 0;
    
    cin>>S;
    
    for(i =0; i<S.size() / 2; i++)
        c += max(S[i], S[S.size() - i - 1]) - min(S[i], S[S.size() - i - 1]);
    
    return c;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    
    return 0;
}
