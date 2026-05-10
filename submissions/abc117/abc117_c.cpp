//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,child,x,...) x
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

int X[100000];
int D[100000];
int main(){
  int N, M;
  cin >> N >> M;
  rep(i, M) cin >> X[i];
  sort(X, X + M);
  rep(i, M - 1) D[i] = X[i + 1] - X[i];
  sort(D, D + M - 1);
  ll ans = 0;
  rep(i, max(0, M - N)) ans += D[i];
  cout << ans << endl;
  return 0;
}
