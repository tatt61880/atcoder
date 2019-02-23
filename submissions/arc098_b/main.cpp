//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin
,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const int MOD = 1e9+7;
//}}}

ll xors[200001] = {0};
ll sums[200001] = {0};
ll a[200000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> a[i];
  xors[0] = 0;
  sums[0] = 0;
  rep(i, N){
    xors[i + 1] = xors[i] ^ a[i];
    sums[i + 1] = sums[i] + a[i];
  }
  int l = 1;
  int r = 1;
  int num = 0;
  ll ans = 0;
  while(1){
    if((sums[r] - sums[l - 1]) == (xors[r] ^ xors[l - 1])) {
      //printf("[%d\t%d]\t%lld\t%lld\t%lld\t%lld\n", l, r, sums[l - 1], sums[r], xors[l - 1], xors[r]);
      num++;
      ans += r - l + 1;
      r++;
    }else{
      num = 0;
      l++;
    }
    if(r == N + 1) break;
  }
  cout << ans << endl;
  return 0;
}
