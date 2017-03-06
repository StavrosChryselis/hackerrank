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
#include <ctype.h>

using namespace std;

string S;
int A[26];

inline bool check()
{
    int i;
    
    for(i = 0; i<26; i++)
        if(!A[i])
            return 0;
        
    return 1;
}

int main()
{
    int i;
    
    getline(cin, S);
    
    for(i = 0; i<S.length(); i++)
        if(isalpha(S[i]))
            A[tolower(S[i]) - 'a'] = 1;
    
    if(check())
        printf("pangram\n");
    
    else
        printf("not pangram\n");
    
    return 0;
    
}
