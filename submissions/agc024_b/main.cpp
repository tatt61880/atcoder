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

int a[200000];
int pos[200000];

int main(){
  ll N;
  cin >> N;
  rep(i, N) cin >> a[i];
  rep(i, N){
    pos[a[i] - 1] = i;
  }

  int i = 0;
  int posCurr;
  int posPrev = pos[i];
  int ans = 1;
  int length = 1;
  while(1){
    i++;
    if(i == N) break;
    posCurr = pos[i];
    //printf("[%d %d]", i + 1, posCurr);
    if(posCurr - posPrev > 0){
      length++;
      ans = max(ans, length);
    }else{
      length = 1;
    }
    posPrev = posCurr;
  }
  ans = N - ans;

  cout << ans << endl;
  return 0;
}
