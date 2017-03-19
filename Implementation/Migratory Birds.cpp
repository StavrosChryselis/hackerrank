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

int A[6];

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
    int i, mmax = 0;
    
    for(i = 1; i <= 5; i++)
        mmax = max(mmax, A[i]);
    
    for(i = 1; i <= 5; i++)
        if(mmax == A[i])
            return i;
        
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    
    init();
    cout<<solve()<<"\n";
    
    return 0;
}
