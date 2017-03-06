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
#include <algorithm>
#include <string>
using namespace std;

int A[26];
string S;

inline void init()
{
    int i;
    
    for(i = 0; i<26; i++)
        cin>>A[i];
    
    cin>>S;   
}

inline int solve()
{
    int mmax = 0;
    int i;
    
    for(i = 0; i<S.size(); i++)
        mmax = max(mmax, A[S[i] - 'a']);
    
    return mmax * S.size();
}

int main()
{
    init();
    cout<<solve()<<endl;
    
    return 0;
}
