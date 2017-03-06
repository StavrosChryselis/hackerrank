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
#include <string>

using namespace std;

string S;
long long sum[101];
long long N;

inline void init()
{
    cin>>S;
    cin>>N;
    
    if(S[0] == 'a')
        sum[0] = 1;
    
    for(int i = 1; i<S.size(); i++)
    {
        sum[i] = sum[i - 1];
        if(S[i] == 'a')
            sum[i]++;
    }
}

inline long long solve()
{
    if(N % S.size() == 0)
        return sum[S.size() - 1] * N / S.size();
    
    long long rval = N / S.size() * sum[S.size() - 1];
    N %= S.size();
    N--;
    
    rval += sum[N];
    
    return rval;
}

int main()
{
    init();
    printf("%lld\n", solve());
    
    return 0;
}
