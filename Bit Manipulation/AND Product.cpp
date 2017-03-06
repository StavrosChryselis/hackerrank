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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long A, B;

inline long long solve()
{
    long long sum = 0;
    long long AA = A, BB = B;
    long long val = 1;
    
    while(A || B)
    {
        if(A % 2 && B % 2 && BB - AA < val)
            sum += val;
        val *= 2;
        A /= 2;
        B /= 2;
    }
    
    return sum;
}
int main() 
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%lld %lld", &A, &B);
        printf("%lld\n", solve());
    }
    return 0;
}
