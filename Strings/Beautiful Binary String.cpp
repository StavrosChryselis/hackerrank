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

using namespace std;

int N;
string S;

inline void init()
{
    cin>>N;
    cin>>S;
}

inline int solve()
{
    int ans = 0, i;
    
    for(i = 2; i<N; i++)
        if(S[i - 2] == '0' && S[i - 1] == '1' && S[i] == '0')
        {
            ans++;
            S[i] = '1';
        }
    
    return ans;
}

int main()
{
    init();
    cout<<solve()<<endl;
    
    return 0;
}
