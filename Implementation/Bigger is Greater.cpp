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
#include <iostream>
#include <algorithm>

using namespace std;

string S;

inline void init()
{
    cin>>S;
}

inline void solve()
{
    if(next_permutation(S.begin(), S.end()))
        cout<<S<<endl;
    else
        cout<<"no answer"<<endl;
}

int main()
{
    int T;
    
    cin>>T;
    
    while(T--)
    {
        init();
        solve();
    }
    
    return 0;
}
