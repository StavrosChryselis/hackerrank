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

#include <vector>
#include <string.h>
#include <deque>
#include <stdio.h>
using namespace std;

vector< vector< int > > G;
int dist[1007];
int N, M, S;

inline void init()
{
    int i, f, s;
    
    scanf("%d", &N);
    scanf("%d", &M);
    G.clear();
    G.resize(N + 1);
    memset(dist, -1, sizeof(dist));
    
    for(i = 0; i<M; i++)
    {
        scanf("%d %d", &f, &s);
        G[f].push_back(s);
        G[s].push_back(f);
    }
    
    scanf("%d", &S);
}

inline void solve()
{
    deque< pair<int, int> > Q;
    pair<int, int> curr;
    int i;
    
    Q.push_back(make_pair(S, 0));
    
    while(!Q.empty())
    {
        curr = Q.front();
        Q.pop_front();
        
        for(i = 0; i<G[curr.first].size(); i++)
            if(dist[G[curr.first][i]] == -1)
            {
                Q.push_back(make_pair(G[curr.first][i], curr.second + 6));
                dist[G[curr.first][i]] = curr.second + 6;
             }
                
    }
    
}

inline void print()
{
    int i;
    
    for(i = 1; i<=N; i++)
        if(i != S)
            printf("%d ", dist[i]);
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
        print();
    }
    
    return 0;
}
