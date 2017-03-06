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

int A[100007];
int N;

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
}

inline int solve()
{
    int i;
    int sum;
    
    int leftsum[100007];
    
    if(N == 1)
        return 1;
    
   leftsum[0] = 1;
    
   for(i = 1; i< N; i++)
   {
       if(A[i] > A[i - 1])
           leftsum[i] = leftsum[i - 1] + 1;
       else
           leftsum[i] = 1;       
    }
   
   for(i = N - 2; i >= 0; i--)
   {
       if(A[i] > A[i + 1] && leftsum[i] <= leftsum[i + 1])
           leftsum[i] = leftsum[i + 1] + 1;
   }
    
    sum = 0;
   for(i = 0; i<N; i++)
       sum += leftsum[i];
    return sum;
   
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
