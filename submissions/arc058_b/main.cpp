//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,begin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll MOD=(ll)1e9+7;
//}}}

ll f1[200001] = {0};
ll f2[200001] = {0};
ll comb1[200001];
ll comb2[200001];

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

ll comb_mod1(int n, int r){
  return (((f1[n] * mod_inv(f1[r])) % MOD) * mod_inv(f1[n-r])) % MOD;
}
ll comb_mod2(int n, int r){
  return (((f2[n] * mod_inv(f2[r])) % MOD) * mod_inv(f2[n-r])) % MOD;
}

int main(){
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  ll ans = 0;

  {
    int N = H - A + B - 1;
    f1[0] = f1[1] = 1;
    rep(i, 2, N + 1) f1[i] = (i * f1[i-1]) % MOD;
    rep(i, N + 1) comb1[i] = comb_mod1(N, i);
  }
  {
    int N = W - B + A - 1;
    f2[0] = f2[1] = 1;
    rep(i, 2, N + 1) f2[i] = (i * f2[i-1]) % MOD;
    rep(i, N + 1) comb2[i] = comb_mod2(N, i);
  }

  rep(i, min(W - B, H - A)){
    ans += comb1[B + i] * comb2[A + i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
