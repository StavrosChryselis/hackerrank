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
#include <vector>

using namespace std;

int MAP[1007], ARR[1007];

int main()
{
    int N, i;
      
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &ARR[i]);
        MAP[ARR[i]]++;
    }
    
    sort(ARR, ARR + N);
    int t = N;
    
    for(i = 1; i<N; i++)
        if(ARR[i] != ARR[i - 1])
        {
            printf("%d\n", t);
            t -= MAP[ARR[i-1]];
        }
    
    printf("%d\n", t);
    return 0;
}
