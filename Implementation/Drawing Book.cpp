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
#include <algorithm>

using namespace std;

int main()
{
    int A, B;
    
    cin >> A >> B;
    
    A /= 2;
    A++;
    
    B /= 2;
    B++;
    
    cout << min(A - B, B - 1) << endl;
    
    return 0;
    
    
}
