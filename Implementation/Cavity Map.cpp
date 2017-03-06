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

#define gc() getchar()
using namespace std;

char A[128][128];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N;

inline void init()
{
    int i, j;
    
    scanf("%d\n", &N);
    
    for(i = 1; i<=N; i++)
    {
        for(j = 1; j<=N; j++)
            A[i][j] = gc();
        gc();
    }
       
}

inline void fix(int x, int y)
{
    int i;
    
    for(i = 0;i<4; i++)
        if(A[x + dx[i]][y + dy[i]] == 'X' || A[x + dx[i]][y + dy[i]] >= A[x][y])
            return;
    
    A[x][y] = 'X';
}

inline void solve()
{
    int i, j;
    
    for(i = 2; i<N; i++)
        for(j = 2; j<N; j++)
            fix(i, j);
}

inline void print()
{
    int i, j;
    
    for(i = 1; i<=N; i++)
    {
        for(j = 1; j<=N; j++)
            putchar(A[i][j]);
        putchar('\n');
    }
}

int main()
{
    init();
    solve();
    print();
    
    return 0;
}
