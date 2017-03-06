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

inline int solve()
{
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    b = (b + c - 1) % a;
    
    if(!b)
        return a;
    return b;
}

int main() 
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
        printf("%d\n", solve());
    return 0;
}
