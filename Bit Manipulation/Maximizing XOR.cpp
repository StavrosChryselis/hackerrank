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
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
int MAX = 0;

    int i, j;
    
    for(i = l; i<r; i++)
        for(j = i + 1; j <=r; j++)
            MAX = max(MAX, i ^j);
    return MAX;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
