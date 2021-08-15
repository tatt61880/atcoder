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

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

ll gcd2(ll a, ll b){
  if(a == -1) return b;
  if(b == -1) return a;
  return gcd(a, b);
}

const int kMaxN = 131072;
ll dat[kMaxN * 2 - 1];
int n;
void update(int i, ll x){
  i += n - 1;
  dat[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    dat[i] = gcd2(dat[i * 2 + 1], dat[i * 2 + 2]);
  }
}

ll query(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return -1;
  if(a <= l && r <= b) return dat[k];
  else{
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return gcd2(vl, vr);
  }
}

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  n = kMaxN;
  rep(i, 2 * n - 1) dat[i] = -1;
  rep(i, N) update(i, A[i]);
  rep(i, N, n) update(i, -1);

  ll ans = 0;
  rep(i, N){
    ll v = gcd2(query(0, i, 0, 0, n), query(i + 1, N, 0, 0, n));
    ans = max(ans, v);
  }
  cout << ans << endl;
  return 0;
}
