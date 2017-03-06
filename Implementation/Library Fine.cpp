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

using namespace std;

int D, M, Y;
int ED, EM, EY;

inline void init()
{
    scanf("%d %d %d", &D, &M, &Y);
    scanf("%d %d %d", &ED, &EM, &EY);
}

inline int solve()
{
    if(Y < EY)
        return 0;
    
    if(Y == EY && M < EM)
        return 0;
    
    if(Y == EY && M == EM && D < ED)
        return 0;
    
    if(Y > EY)
        return 10000;
    
    if(M > EM)
        return (M - EM) * 500;
    
    if(D > ED)
        return (D - ED) * 15;
    
    return 0;
}

int main()
{
    init();
    printf("%d\n", solve());
    return 0;
}
