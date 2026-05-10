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

int main(){
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int ans = 0;
  rep(a, A + 1){
    rep(b, B + 1){
      rep(c, C + 1){
        if(a * 500 + b * 100 + c * 50 == X) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
