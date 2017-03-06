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


int main() 
{
    int T, num;
    
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d", &num);
        if(num % 8)
            printf("First\n");
        else
            printf("Second\n");
    }
    return 0;
}
