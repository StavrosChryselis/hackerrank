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
#include <string>

using namespace std;

string S;

inline int solve()
{
    int ans = 0, i;
    
    for(i = 1; i<S.length(); i++)
        if(S[i] == S[i-1])
            ans++;
        
   return ans; 
    
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    while(N--)
    {
        cin>>S;
        printf("%d\n", solve());
        
    }
    return 0;
}
