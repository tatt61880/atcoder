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
  int n, m, d;
  cin >> n >> m >> d;
  double p;
  if (d == 0) {
    p = 1.0 / n;
  } else if (d + 1 > n - d) {
    p = 1.0 / n;
  } else {
    p = 1.0 * 2 * d + 2.0 * (n - 2 * d);
    p /= n;
    p /= n;
  }
  double ans = p * (m - 1);
  printf("%0.10lf\n", ans);
  return 0;
}
