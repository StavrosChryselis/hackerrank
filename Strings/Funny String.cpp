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

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

string A, B;

inline void init()
{
    getline(cin, A);
    B = A;
    reverse(B.begin(), B.end());
}

inline bool check()
{
    int i, f, s;
    
    for(i = 1; i<A.length(); i++)
    {
        f = A[i] - A[i - 1];
        if(f < 0)
            f = -f;
        
        s = B[i] - B[i-1];
        if(s < 0)
            s = -s;
        
        if(f != s)
            return 0;
    }
    
    return 1;
}

int main()
{
    int T;
    
    scanf("%d\n", &T);
    
    while(T--)
    {
        init();
        if(check())
            printf("Funny\n");
        else
            printf("Not Funny\n");
    }
    
    return 0;
}
