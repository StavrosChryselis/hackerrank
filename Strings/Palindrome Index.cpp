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
#include <stdio.h>
#include <string>

using namespace std;

inline int solve()
{
    int i, left = -1, right = -1;
    string S;
    
    cin>>S;
    
    for(i = 0; i<S.size() / 2; i++)
        if(S[i] != S[S.size() -1 - i])
        {
            left = i;
            right = S.size() -1 - i;
            break;
        }
    
    if(left == -1)
        return -1;
    
    for(i = left + 1; i < S.size() / 2; i++)
        if(S[i] != S[S.size() - i])
            return right;
    
    return left;
}
int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    
    return 0;
}
