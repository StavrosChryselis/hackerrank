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

using namespace std;

int N;

int A[100];

inline void init()
{
    int num;
    string s;
    
    scanf("%d", &N);
    
    while(N--)
    {
        cin>>num>>s;
        A[num]++;
    }
    
    for(int i = 1; i< 100; i++)
        A[i] += A[i - 1];
}

inline void print()
{
    for(int i = 0; i < 100; i++)
        printf("%d ", A[i]);
    
    puts("");
}

int main()
{
    init();
    print();
    
    return 0;
}
