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
  int N;
  cin >> N;
  int T = 0;
  int X = 0;
  int Y = 0;
  rep(i, N){
    int t, x, y;
    cin >> t >> x >> y;
    if((t - T) % 2 != (x + y - X - Y) % 2){
      puts("No");
      return 0;
    }
    if(t - T < (abs(x - X) + abs(y - Y))){
      puts("No");
      return 0;
    }
    t = T;
    x = X;
    y = Y;
  }
  puts("Yes");
  return 0;
}
