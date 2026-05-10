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
const ll MOD = 1e9+7;
//}}}

int p[10];
int c[10];

int main(){
  int D, G;
  cin >> D >> G;
  int ans = 10000;
  rep(i, D){
    cin >> p[i];
    cin >> c[i];
  }
  rep(i, 1 << D){
    int sum = 0;
    int count = 0;
    rep(j, D){
      if((i >> j) & 1){
        count += p[j];
        sum += c[j];
        sum += p[j] * (j + 1) * 100;
      }
    }
    for(int j = D - 1; j >= 0; j--){
      if(sum >= G)break;
      if(!((i >> j) & 1)){
        if(sum + p[j] * (j + 1) * 100 < G){
          count += p[j];
          sum += p[j] * (j + 1) * 100;
        }else{
          int n = (G - sum + (((j + 1) * 100) - 1)) / ((j + 1) * 100);
          count += n;
          break;
        }
      }
    }
    ans = min(count, ans);
  }
  cout << ans << endl;
  return 0;
}
