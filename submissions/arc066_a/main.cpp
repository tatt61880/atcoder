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
const ll MOD = 1e9+7;
//}}}

int a[100000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> a[i];
  sort(a, a+N);

  int ans = 1;
  rep(i, N){
    if(a[i] != (i + 2 - N % 2) / 2 * 2 + N % 2 - 1){
      cout << 0 << endl;
      return 0;
    }
    if (i % 2) {
      ans *= 2;
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
