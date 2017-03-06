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
using namespace std;
unsigned long long W, B, X, Y, Z;

inline void init()
{
    cin>>B>>W>>X>>Y>>Z;
}

inline unsigned long long solve()
{
    if(X + Z < Y)
        return X * B + (X + Z) * W;
    
    if(Y + Z < X)
        return Y * W + (Y + Z) * B;
    
    return Y * W + X * B;
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    while(N--)
        {
        init();
        cout<<solve()<<endl;
    }
    
    return 0;
}
