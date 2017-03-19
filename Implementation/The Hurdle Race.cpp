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

using namespace std;

int N, M;

inline void solve()
{
    int num, mmax = 0;
    
    cin>>N>>M;
    
    while(N--)
    {
        cin>>num;
        mmax = max(mmax, num);
    }
    
    if(mmax > M)
        cout<<mmax - M<<"\n";
    else
        cout<<"0\n";
}

int main()
{
    ios::sync_with_stdio(0);
    
    solve();
    
    return 0;
}
