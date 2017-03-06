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

int one, two;

inline void init()
{
    int N, num;
    
    cin>>N;
    one = two = 0;
    while(N--)
    {
        cin>>num;
        
        if(num % 3 == 1)
            one++;
        else if(num % 3 == 2)
            two++;
    }
}

inline void solve()
{
    if(one % 2 == 0 && two % 2 == 0)
        cout<<"Koca\n";
    else
        cout<<"Balsa\n";
}

int main()
{
    ios::sync_with_stdio(0);
    
    int T;
    
    cin>>T;
    
    while(T--)
    {
        init();
        solve();
    }
    
    return 0;
}
