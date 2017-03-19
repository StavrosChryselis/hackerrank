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
#include <stdlib.h>
#include <math.h>

using namespace std;

int x, y, z;

inline void init()
{
    cin>>x>>y>>z;
}

inline void solve()
{
    int A, B;
    
    A = abs(x - z);
    B = abs(y - z);
    
    if(A < B)
    {
        cout<<"Cat A\n";
        return;
    }
    
    else if(B < A)
    {
        cout<<"Cat B\n";
        return;
    }
    
    cout<<"Mouse C\n";
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
