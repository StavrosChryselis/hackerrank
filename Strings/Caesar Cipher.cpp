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
#include <ctype.h>
#include <string>
#include <iostream>

using namespace std;

string S;
int N, K;

inline void init()
{
    cin>>N;
    cin>>S;
    cin>>K;
}

inline void solve()
{
    int i;
    
    for(i = 0; i<N; i++)
        if(isalpha(S[i]))
        {
            if(S[i] == tolower(S[i]))
                S[i] = (S[i] - 'a' + K) % 26 + 'a';
            else
                S[i] = (S[i] - 'A' + K) % 26 + 'A';
        }
}
    
int main()
{
    init();
    solve();
    cout<<S<<endl;
    
    return 0;
}
