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

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
/* Head ends here */

int stringReduction(char a[]) {
    int A[3];
    
    A[0] = A[1] = A[2] = 0;
    
    for(int i = 0; i<strlen(a); i++)
        A[a[i] - 'a']++;
    
    if(!A[0] && !A[1] || !A[0] && !A[2] || !A[1] && !A[2])
        return strlen(a);
    
    if(A[0] % 2 == A[1] % 2 && A[1] % 2 == A[2] % 2)
        return 2;
    
    return 1;
}

int main() {
    int res, t, i;
    scanf("%d",&t);
    char a[100001];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        res=stringReduction(a);
        printf("%d\n",res);  
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
