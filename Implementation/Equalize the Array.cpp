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

#define MAXVAL 100
using namespace std;

int N, mmax;
int A[MAXVAL + 1];

inline void init()
{
    int i, num;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        A[num]++;
        mmax = max(mmax, A[num]);
    }
    
    printf("%d\n", N - mmax);
}

int main()
{
    init();
    return 0;
}


