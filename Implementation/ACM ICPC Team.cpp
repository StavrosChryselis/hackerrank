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
#include <bitset>
#include <algorithm>

#define gc() getchar()
using namespace std;

bitset<507> B[507];
int N, M;

inline void getbitset(bitset<507> &BB)
{
    char c;
    int i;
    
    c = gc();
    
    while(isspace(c))
        c = gc();
    
    for(i = 0; i<M; i++)
    {
        BB[i] = c - '0';
        c = gc();
    }
}

inline void init()
{
    int i;
    
    scanf("%d %d", &N, &M);
    
    for(i = 0; i<N; i++)
        getbitset(B[i]);
}

inline void solve()
{
    int i, j, MAX = 0;
    bitset<507> temp;
    
    for(i = 0; i<N - 1; i++)
        for(j = i + 1; j < N; j++)
        {
            temp = B[i] | B[j];
            MAX = max(MAX, (int)temp.count());
        }
    
    int c = 0;
    
    for(i = 0; i<N - 1; i++)
        for(j = i + 1; j < N; j++)
        {
            temp = B[i] | B[j];
            if((int) temp.count() == MAX)
                c++;
        }
   
    printf("%d\n%d\n", MAX, c);
}

int main()
{
    init();
    solve();
    
    return 0;
}
