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

#include <set>
#include <stdio.h>
#include <vector>

using namespace std;

int N, A, B;

inline void init()
{
    scanf("%d %d %d", &N, &A, &B);
}

inline void solve()
{
    set< pair<int, int > > Q;
    int i;
    
    Q.insert(make_pair(1, 0));
    
    while(Q.begin()->first != N)
    {
        Q.insert(make_pair(Q.begin()->first + 1, Q.begin()->second + A));
        Q.insert(make_pair(Q.begin()->first + 1, Q.begin()->second + B));
        Q.erase(Q.begin());
    }
    
    for(set<pair<int ,int> >::iterator ii = Q.begin(); ii != Q.end(); ii++)
        printf("%d ", ii->second);
    putchar('\n');
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        init();
        solve();
    }
    
    return 0;
}
