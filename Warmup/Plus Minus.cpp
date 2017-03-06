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
    float N;
    int i, pos, neg, z, num;
    
    pos = neg = z = 0;
    
    scanf("%f", &N);
    
    for(i = 0; i<N; i++)
    {
        scanf("%d", &num);
        
        if(num > 0)
            pos++;
        else if(num < 0)
            neg++;
        else
            z++;
    }
    
    printf("%.6f\n%.6f\n%.6f\n", pos / N, neg / N, z / N);
    
    return 0;
}
