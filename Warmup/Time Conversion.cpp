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

int main()
{
    int h, m, s;
    char c;
    
    scanf("%d:%d:%d%c", &h, &m, &s, &c);
    
    if(c == 'A')
        printf("%02d:%02d:%02d\n", h % 12, m, s);
    else
        printf("%02d:%02d:%02d\n", h % 12 + 12, m, s);
    
    return 0;
}
