//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,begin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)998244353;
//}}}

ll nums[100001];
int main(){
  int N;
  cin >> N;
  rep(i, N){
    int D;
    cin >> D;
    if(i == 0){
      if(D != 0){
        cout << 0 << endl;
        return 0;
      }
    }
    nums[D]++;
  }

  if(nums[0] != 1){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  int num = 1;
  int i = 1;
  while(1){
    if(nums[i] == 0) {
      if(N == 1){
        ans = 1;
      }else{
        ans = 0;
      }
      break;
    }
    rep(j, nums[i]){
      ans *= nums[i - 1];
      ans %= mod;
    }
    num += nums[i];
    if(num == N) {
      break;
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}
