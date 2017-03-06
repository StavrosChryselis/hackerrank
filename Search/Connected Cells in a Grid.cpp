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

using namespace std;

int N, M;
int board[15][15];
bool V[15][15];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

inline void init()
{
    int i, j;
    
    scanf("%d %d", &N, &M);
    
    
    for(i = 1; i<=N; i++)
        for(j = 1; j<=M; j++)
            scanf("%d", &board[i][j]);
}

int dfs(int x, int y, int val)
{
    int sum = 0;
    
    for(int i = 0; i< 8; i++)
        if(board[x + dx[i]][y + dy[i]] && !V[x + dx[i]][y + dy[i]])
        {
            V[x + dx[i]][y + dy[i]] = 1;
            sum += dfs(x + dx[i], y + dy[i], val + 1);
        }
    
    return sum + 1;
}

inline int solve()
{
    int i, j, MAX = 0;
    
    for(i = 1; i<=N; i++)
        for(j = 1; j<=M; j++)
            if(board[i][j] && !V[i][j])
            {
                V[i][j] = 1;
                MAX =max(MAX, dfs(i, j, 1));
            }
    
    return MAX;
}
int main()
{
    init();
    
    printf("%d\n", solve());
    
    return 0;
}
