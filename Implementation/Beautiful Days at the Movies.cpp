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
#include <string>
#include <math.h>

using namespace std;

int a, b, K;

inline void init()
{
    scanf("%d %d %d", &a, &b, &K);
}

inline int reverse(int num)
{
    string S = to_string(num);
    
    reverse(S.begin(), S.end());
    
    return stoi(S);
}

inline int solve()
{
    int rval = 0, i;
    
    for(i = a; i<=b; i++)
        if(abs(i - reverse(i)) % K == 0)
            rval++;
        
    return rval;
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
