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
#include <vector>

using namespace std;

int pivot;

inline void solve()
{
    int i, N, num;
    vector<int> left, equal, right;
    
    scanf("%d", &N);
    
    scanf("%d", &pivot);
    equal.push_back(pivot);
    
    for(i = 0; i < N - 1; i++)
    {
        scanf("%d", &num);
        if(num < pivot)
            left.push_back(num);
        else if(num == pivot)
            equal.push_back(num);
        else
            right.push_back(num);
    }
    
    for(i = 0; i<left.size(); i++)
        printf("%d ", left[i]);
    
    for(i = 0; i<equal.size(); i++)
        printf("%d ", equal[i]);
    
    for(i = 0; i<right.size(); i++)
        printf("%d ", right[i]);
}

int main()
{
    solve();
    return 0;
}
