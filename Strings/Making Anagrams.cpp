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
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A, B;
int MEMOA[26], MEMOB[26];

inline void init()
{
    int i;
    
    cin>>A;
    cin>>B;
    
    for(i = 0; i< A.size(); i++)
        MEMOA[A[i] - 'a']++;
    
    for(i = 0; i< B.size(); i++)
        MEMOB[B[i] - 'a']++;
}

inline int solve()
{
    int c = 0;
    int i;
    
    for(i = 0; i<26; i++)
        c += max(MEMOA[i], MEMOB[i]) - min(MEMOA[i], MEMOB[i]);
    
    return c;
}

int main()
{
    init();
    printf("%d\n", solve());
    return 0;
}
