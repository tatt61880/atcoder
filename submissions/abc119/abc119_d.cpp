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
const ll mod=(ll)1e9+7;
//}}}

const ll inf = 1e18;

int A, B, Q;
ll s[100000];
ll t[100000];

ll g(ll si, ll ti, ll x){
  ll res = inf;
  rep(ds, -1, 1){
    rep(dt, -1, 1){
      int sii = si + ds;
      int tii = ti + dt;
      if(sii >= A) continue;
      if(tii >= B) continue;
      if(sii < 0) continue;
      if(tii < 0) continue;
      ll sx = s[sii];
      ll tx = t[tii];
      res = min(res, abs(sx - tx) + min(abs(x - sx), abs(x - tx)));
    }
  }
  return res;
}

ll f(ll x){
  ll si, ti;
  {
    ll ng = 0;
    ll ok = A - 1;
    while(abs(ok - ng) > 1){
      ll md = (ok + ng) / 2;
      (s[md] >= x ? ok : ng) = md;
    }
    si = ok;
  }
  {
    ll ng = 0;
    ll ok = B - 1;
    while(abs(ok - ng) > 1){
      ll md = (ok + ng) / 2;
      (t[md] >= x ? ok : ng) = md;
    }
    ti = ok;
  }
  return g(si, ti, x);
}

int main(){
  cin >> A >> B >> Q;
  rep(i, A) cin >> s[i];
  rep(i, B) cin >> t[i];
  rep(i, Q){
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", f(x));
  }
  return 0;
}
