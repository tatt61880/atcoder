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
const ll MOD = (ll)1e9+7;
//}}}
int a[100002];
int ab[100000];
int b[100000];
int bc[100000];
int c[100000];
int main(){
  int N;
  cin >> N;
  a[0] = 0;
  rep(i, N) cin >> a[i + 1];
  a[N + 1] = 0;
  int sum = 0;
  rep(i, N + 1){
    sum += abs(a[i] - a[i + 1]);
  }
  rep(i, N){
    int ans;
    ans = sum;
    ans -= abs(a[i + 1] - a[i]) + abs(a[i + 2] - a[i + 1]) - abs(a[i + 2] - a[i]);
    cout << ans << endl;
  }
  return 0;
}
