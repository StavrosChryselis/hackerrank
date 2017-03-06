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

using namespace std;

vector<pair<int, int> > A;
int N;

inline void init()
{
    int f, s, i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d %d", &f, &s);
        A.push_back(make_pair(f + s, i + 1));
    }
}

inline void solve()
{
    sort(A.begin(), A.end());
    
    for(int i = 0; i<N; i++)
        printf("%d ", A[i].second);
}

int main() 
{
    init();
    solve();
    return 0;
}
