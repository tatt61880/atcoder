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
  int N, Y;
  cin >> N >> Y;
  Y /= 1000;
  rep(i, N + 1){
    rep(j, N + 1 - i){
      int k = N - i - j;
      if(k < 0) continue;
      if(i * 10 + j * 5 + k == Y){
        printf("%d %d %d\n", i, j, k);
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
