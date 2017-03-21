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
#include <climits>
#include <cstdlib>
#include <cmath>

#define MAXN 100007
using namespace std;

int N;
int A[MAXN];

inline void init()
{
    int i;
    
    cin>>N;
    
    for(i = 0; i < N; i++)
        cin>>A[i];
    
    sort(A, A + N);
}

inline int solve()
{
    int rval = INT_MAX;
    int i;
    
    for(i = 1; i < N; i++)
        rval = min(rval, abs(A[i] - A[i - 1]));
    
    return rval;
}

int main()
{
    ios::sync_with_stdio(0);
    
    init();
    cout<<solve()<<"\n";
    
    return 0;
}
