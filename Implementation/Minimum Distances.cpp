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
#include <limits.h>

using namespace std;

int N;
int A[100007];

inline int solve()
{
    int i, num, ans = INT_MAX;
    
    scanf("%d", &N);
    
    for(i = 1; i<=N; i++)
    {
        scanf("%d", &num);
        if(A[num] == 0)
            A[num] = i;
        else
            ans = min(ans, i - A[num]);
    }
    
    if(ans == INT_MAX)
        return -1;
    
    return ans;
}

int main()
{
    printf("%d\n", solve());
    
    return 0;
}
