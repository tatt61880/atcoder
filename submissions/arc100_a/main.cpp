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

ll a[200000];
ll sum[200000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> a[i];
  rep(i, N) a[i] -= (i + 1);
  sort(a, a + N);
  ll a0 = a[0];
  rep(i, N) a[i] -= a0;
  sum[0] = a[0];
  rep(i, 1, N) sum[i] = sum[i - 1] + a[i];
  ll ans = sum[N - 1];
  rep(i, N){
    ll ansI = a[i] * (i + 1) - sum[i];
    ansI += sum[N - 1] - sum[i] - a[i] * (N - 1 - i);
    ans = min(ans, ansI);
  }

  cout << ans << endl;
  return 0;
} 
