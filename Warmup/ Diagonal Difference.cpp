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

using namespace std;

int main()
{
    int N, i, j, num;
    long long sumA = 0, sumB = 0;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        for(j = 0; j<N; j++)
        {
            scanf("%d", &num);
        
            if(i == j)
                sumA += num;
            
            if(i + j == N - 1)
                sumB += num;
        }
    
    sumA = sumA - sumB;
    if(sumA < 0)
        sumA = -sumA;
    
    printf("%lld\n", sumA);
    
    return 0;
}
