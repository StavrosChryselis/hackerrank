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
#include <string>

using namespace std;

int N;
int A[26];

inline void init()
{
    int i, j;
    string S;
    
    scanf("%d", &N);
    
    for(i = 1; i<=N; i++)
    {
        cin>>S;
        
        for(j = 0; j <S.size(); j++)
           if(A[S[j] - 'a'] == i - 1)
                A[S[j] - 'a'] = i;
    }
    
}

inline int solve()
{
    int i, c = 0;
    
    for(i = 0; i<26; i++)
        if(A[i] == N)
            c++;
        
    return c;
    
    
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
