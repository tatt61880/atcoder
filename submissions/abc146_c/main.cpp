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
ll digit(ll num){
  int res = 0;
  while(num){
    num /= 10;
    res++;
  }
  return res;
}
bool f(ll N, ll A, ll B, ll X){
  ll need = A * N + B * digit(N);
  return need <= X;
}
int main(){
  ll A, B, X;
  cin >> A >> B >> X;
  ll ans = 0;
  ll ok = 0;
  ll ng = 1e9 + 1;
  while(abs(ok - ng) > 1){
    ll md = (ok + ng) / 2;
    (f(md, A, B, X) ? ok : ng) = md;
  }
  ans = ok;
  cout << ans << endl;
  return 0;
}
