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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<int> A;

inline void init()
{
    int num;
    
    scanf("%d", &N);
    
    while(N--)
    {
        scanf("%d", &num);
        A.push_back(num);
    }
}

int main() 
{
    init();
    
    nth_element (A.begin(), A.begin()+A.size() / 2, A.end());
    printf("%d\n", A[A.size() / 2]);
    
    return 0;
}
