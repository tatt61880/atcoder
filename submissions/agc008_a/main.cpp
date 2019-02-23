//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) fo
r(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

int main(){
  int x, y;
  cin >> x >> y;
  int ans = 0;
  if(x >= 0){
    if(y > x){
      ans = y - x;
    }else{
      if(y <= -x){
        ans = ((-y) - x) + 1;
      }else{
        ans = min(1 + x - y + 1, 1 + (y - (-x)));
      }
    }
  }else{
    if(y < x){
      ans = 1 + (x - y) + 1;
    }else{
      if(y > -x){
        ans = 1 + (y - (-x));
      }else{
        ans = min(y - x, ((-y) - x) + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
