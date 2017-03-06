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
#include <vector>
#include <ctype.h>

#define gc() getchar()
using namespace std;

inline void solve()
{
    vector<char> A;
    int i;
    char c;
    
    c = gc();
    
    while(isalpha(c))
    {
        if(A.empty())
            A.push_back(c);
        else
        {
            if(A.back() == c)
                A.pop_back();
            else
                A.push_back(c);
        }
        
        c = gc();
    }
    
    if(A.empty())
        printf("Empty String");
    else
        for(i = 0; i<A.size(); i++)
            putchar(A[i]);
    putchar('\n');    
}

int main()
{
    solve();
    
    return 0;
}
