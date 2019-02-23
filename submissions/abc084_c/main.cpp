//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,b
egin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

int main(){
  int N;
  cin >> N;
  int c[500];
  int s[500];
  int f[500];
  rep(i, N - 1){
    cin >> c[i] >> s[i] >> f[i];
  }
  rep(i, N){
    int ans = 0;
    rep(j, i, N - 1){
      if(ans < s[j]) ans = s[j];
      if(ans % f[j]) ans += f[j] - (ans % f[j]);
      ans += c[j];
    }
    cout << ans << endl;
  }
  return 0;
}
