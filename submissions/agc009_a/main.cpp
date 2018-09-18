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

ll a[100000];
ll b[100000];
int main(){
  ll N;
  cin >> N;
  rep(i, N){
    cin >> a[i] >> b[i];
  }
  reverse(a, a + N);
  reverse(b, b + N);

  ll sum = 0;
  ll ans = 0;
  rep(i, N){
    ll A = a[i] + sum;
    ll B = b[i];
    if(A % B){
      ll C = B - A % B;
      sum += C;
      ans += C;
    }
  }
  cout << ans << endl;
  return 0;
}
