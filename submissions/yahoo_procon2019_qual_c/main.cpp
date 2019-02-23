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
using ll=long long
;
const ll mod=(ll)1e9+7;
//}}}

int main(){
  ll K, A, B;
  cin >> K >> A >> B;
  if(B - A <= 2 || K - A <= 0){
    ll ans = K + 1;
    cout << ans << endl;
    return 0;
  }
  ll ans = 0;
  K -= A - 1;
  ans = A;
  if(K % 2){
    ans++;
    K--;
  }
  ans += (B - A) * (K / 2);
  cout << ans << endl;
  return 0;
}
