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

#include <cstdio>
using namespace std;


int main()
{
    int N, i, num;
    long long sum = 0;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        sum += num;
    }
    
    printf("%lld\n", sum);
    
    return 0;
}
