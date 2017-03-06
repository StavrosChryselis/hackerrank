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
#include <algorithm>

#define ll long long
using namespace std;

inline void solve()
{
    ll sum = 0;
    ll num;
    ll mmin, mmax;
 
    scanf("%lld", &num);
    mmin = mmax = sum = num;
    
    for(int i = 0; i< 4; i++)
    {
        scanf("%lld", &num);
        mmin = min(mmin, num);
        mmax = max(mmax, num);
        sum += num;
    }
    
    printf("%lld %lld\n", sum - mmax, sum - mmin);
}

int main()
{
    solve();
    
    return 0;
}
