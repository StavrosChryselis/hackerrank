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

int N, pos;
int sum;
int last;

inline void init()
{
    int i, num;
    
    scanf("%d %d", &N, &pos);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        
        if(i != pos)
            sum += num;
    }
    
    scanf("%d", &last);
}

inline void solve()
{
    if(last == sum / 2)
        printf("Bon Appetit\n");
    else
        printf("%d\n", last - sum / 2);
}

int main()
{
    init();
    solve();
    
    return 0;
}
