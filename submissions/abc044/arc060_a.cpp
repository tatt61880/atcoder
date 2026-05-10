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

ll x[100];
ll sumNum[100][2501] = {0};
int main(){
  int N, A;
  cin >> N >> A;

  rep(i, N){
    cin >> x[i];
  }
  rep(n, N){
    for(int i = n; i >= 1; i--){
      for(int j = 2500; j >= 0; j--){
        if(sumNum[i][j]){
          sumNum[i + 1][j + x[n]] += sumNum[i][j];
        }
      }
    }
    sumNum[1][x[n]]++;
  }

  ll ans = 0;
  rep(n, 1, N + 1){
    ans += sumNum[n][n * A];
  }
  cout << ans << endl;
  return 0;
} 
