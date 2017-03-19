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

using namespace std;

int A[128];

inline void init()
{
    int N, num;
    
    cin>>N;
    
    while(N--)
    {
        cin>>num;
        A[num]++;
    }
}

inline int solve()
{
    int rval = 0, curr, i;
    
    for(i = 2; i <= 100; i++)
    {
        curr = A[i] + A[i - 1];
        rval = max(rval, curr);
    }
    
    return rval;
}

int main()
{
    ios::sync_with_stdio(0);
    
    init();
    cout<<solve()<<"\n";
    
    return 0;
}
