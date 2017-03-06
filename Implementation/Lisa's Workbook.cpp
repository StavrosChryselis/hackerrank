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

int N, K;
int A[128];

int main()
{
    int i, count = 0, start, finish;
    int page = 1;
    
    scanf("%d %d", &N, &K);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
    for(i = 0; i<N; i++)
    {
        start = 1;
        while(A[i])
        {
            finish = start + min(K, A[i]) - 1;
            A[i] -= min(K, A[i]);
            
            if(page >= start && page <= finish)
                count++;
            
            page++;
            start = finish + 1;
        }
            
    }
    
    printf("%d\n", count);
    
    return 0;
}
