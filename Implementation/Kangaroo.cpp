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
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    double x1;
    double v1;
    double x2;
    double v2;
    double ans;
    cin >> x1 >> v1 >> x2 >> v2;
    
    if(v1 == v2 && x1 != x2)
    {
            cout<<"NO\n";
        return 0;
    }
    ans = (x2 - x1) / (v1 - v2);
    
    if(ans == floor(ans) && ans > 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    
    return 0;
}
