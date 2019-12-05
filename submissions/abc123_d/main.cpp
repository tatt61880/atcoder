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
int main()
{
  ll X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X);
  vector<ll> B(Y);
  vector<ll> C(Z);
  rep(i, X) cin >> A[i];
  rep(i, Y) cin >> B[i];
  rep(i, Z) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  vector<ll> v(X * Y);
  int i = 0;
  foreach(a, A){
    foreach(b, B){
      v[i++] = a + b;
    }
  }
  sort(v.rbegin(), v.rend());
  ll v_size = min((int)v.size(), (int)K);
  vector<ll> ans(v_size * Z);
  int ii = 0;
  rep(i, v_size){
    foreach(c, C){
      ans[ii++] = v[i] + c;
    }
  }
  sort(ans.rbegin(), ans.rend());
  rep(i, K){
    cout << ans[i] << endl;
  }
  return 0;
}
