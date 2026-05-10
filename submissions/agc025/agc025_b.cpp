//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const ll MOD = 998244353;
//}}}

ll f[300010] = {0};

ll mod_pow(ll x, ll n){
  ll res = 1LL;
  while(n > 0){
    if(n & 1) res = res * x % MOD;
    x = x*x % MOD;
    n >>= 1;
  }
  return res;
}

ll mod_inv(ll x){
  return mod_pow(x, MOD-2) % MOD;
}

ll comb_mod(int n, int r){
  return (((f[n] * mod_inv(f[r])) % MOD) * mod_inv(f[n-r])) % MOD;
}

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

ll comb[300001];

int main(){
  ll N, A, B, K;
  cin >> N >> A >> B >> K;

  f[0] = f[1] = 1;
  for(int i=2; i<=N; ++i) f[i] = (i * f[i-1]) % MOD;

  rep(i, N + 1){
    comb[i] = comb_mod(N, i);
  }

  ll ans = 0;
  rep(a, 0, N + 1){
    if((K - a * A) % B != 0) continue;
    ll b = (K - a * A) / B;
    if(b < 0) continue;
    if(b > N) continue;

    ll add = comb[a] * comb[b];
    add %= MOD;
    ans += add;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}
