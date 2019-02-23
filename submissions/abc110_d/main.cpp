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
#define rrep3(i,begin,
end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

ll modpow(ll a, ll b){
  if(b == 0) return 1;
  if(b & 1){
    return a * modpow(a, b - 1) % mod;
  }else{
    ll half = modpow(a, b / 2);
    return half * half % mod;
  }
}

ll modfact(ll n){
  ll res = 1;
  rep(i, n) res = res * (i + 1) % mod;
  return res;
}

ll modcomb(ll n, ll r){
  ll res = 1;
  r = min(r, n - r);
  rep(i, r) res = res * (n - i) % mod;
  return res * modpow(modfact(r), mod - 2) % mod;
}

ll modh(ll n, ll r){
  return modcomb(n + r - 1, r);
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> v;
  ll ans = 1;
  rep(n, 2, 100000){
    if(M == 1) break;
    int num = 0;
    while(M % n == 0){
      M /= n;
      num++;
    }
    if(num){
      ans *= modh(N, num);
      ans %= mod;
    }
  }
  if(M != 1){
    ans *= N;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

