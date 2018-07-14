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
const int MOD = 1e9+7;
//}}}
int main(){
  int X;
  cin >> X;
  int ans = 1;
  rep(i, 2, 32){
    int n = i * i;
    while(n <= X){
      ans = max(ans, n);
      n *= i;
    }
  }
  cout << ans << endl;
  return 0;
}
