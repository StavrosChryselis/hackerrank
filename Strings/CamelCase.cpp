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

#include <string>
#include <ctype.h>
#include <iostream>
#include <stdio.h>
using namespace std;

inline int solve()
{
    int ans = 0, i;
    string S;
    
    cin>>S;
    
    for(i = 0; i<S.size(); i++)
        if(S[i] == toupper(S[i]))
            ans++;
        
        return ans + 1;
    
    
}

int main()
{
    printf("%d\n", solve());
    
    return 0;
}
