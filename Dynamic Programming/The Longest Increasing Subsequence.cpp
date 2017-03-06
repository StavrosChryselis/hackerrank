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

#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[1000007];

inline void init()
{
    int i;
    
    scanf("%d", &N);
    
    for(i = 0; i<N; i++)
        scanf("%d", &A[i]);
    
}

inline int solve()
{
    vector<int> LIS;
    vector<int>::iterator ii;
    int i;
    
    LIS.push_back(A[0]);
    
    for(i = 1; i< N; i++)
    {
        if(A[i] > LIS.back())
            LIS.push_back(A[i]);
        
        if(!binary_search(LIS.begin(),LIS.end(), A[i]))
        {
            ii = upper_bound(LIS.begin(), LIS.end(), A[i]);
            *ii = A[i];
        }
    }
    
    return LIS.size();
}

int main()
{
    init();
    printf("%d\n", solve());
    
    return 0;
}
