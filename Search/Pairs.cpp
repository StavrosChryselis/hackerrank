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
#include <unordered_map>

using namespace std;

int N, K;
unordered_map<int, int> MEMO;

inline int solve()
{
    int num;
    int i, c = 0;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        
        if(MEMO.find(num - K) != MEMO.end())
            c += MEMO[num - K];
        
        if(MEMO.find(num + K) != MEMO.end())
            c += MEMO[num + K];
        
        MEMO[num]++;
    }
    
    return c;
}

int main()
{
    printf("%d\n", solve());
    
    return 0;
}
