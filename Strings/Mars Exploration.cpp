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

string S, A = "SOS";

int main()
{
    int i, ans = 0;
    
    cin>>S;
    
    for(i = 0; i< S.length(); i++)
        if(S[i] != A[i % 3])
            ans++;
    cout<<ans<<endl;
    
    return 0;
}
