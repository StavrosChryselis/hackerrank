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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000000007
using namespace std;

int N, M;
long long h, v;

vector< pair<int, int> > V; //0 = h, 1 = v

inline void init()
{
    int i, num;
    
    V.clear();
    h = v = 1;
    scanf("%d %d", &N, &M);
    
    for(i = 0; i< N - 1; i++)
        {
        scanf("%d", &num);
        V.push_back(make_pair(num, 0));
    }
    
    for(i = 0; i< M - 1; i++)
        {
        scanf("%d", &num);
        V.push_back(make_pair(num, 1));
    }
    
    sort(V.begin(), V.end());
}

inline long long solve()
{
    long long sum = 0, prod;
    int i;
    
    for(i = V.size() - 1; i >= 0; i--)
    {
        if(V[i].second)
        {
            prod = h * V[i].first;
            v++;
            sum += prod;
            sum %= MOD;
        }
        
        else
        {
            prod = v * V[i].first;
            h++;
            sum += prod;
            sum %= MOD;
        }
    }
    
    return sum;
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        {
        init();
        printf("%lld\n", solve());
    }
    return 0;
}
