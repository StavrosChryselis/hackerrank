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

#define MOD 1000000007
using namespace std;

long long N;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

inline long long solve()
{
    int i;
    long long M, num, ans = 0;
    
    scanf("%lld", &N);
    M = modpow(2*1LL, N - 1, MOD * 1LL);
    
    while(N--)
    {
        scanf("%lld", &num);
        ans |= num;
    }
    
    ans *= M;
    ans %= MOD;
    
    return ans;
}

int main()
{
    int T;
    
    scanf("%d", &T);
    while(T--)
        printf("%lld\n", solve());
    
    return 0;
}
