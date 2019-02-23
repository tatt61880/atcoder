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
const int MOD = 1e9+7;
//}}}

int f[100] = {0};
int p[100][11];

int countSameBitNum(int n, int m){
  int res = 0;
  while(n && m){
    if((n & 1) && (m & 1)) res++;
    n /= 2;
    m /= 2;
  }
  return res;
}

int main(){
  int N;
  cin >> N;
  rep(i, N){
    rep(j, 10){
      int ff;
      cin >> ff;
      f[i] += ff;
      f[i] *= 2;
    }
    f[i] /= 2;
  }
  rep(i, N){
    rep(j, 11){
      cin >> p[i][j];
    }
  }

  int ans = 0;
  rep(i, 1, 1024){
    int sum = 0;
    rep(j, N){
      sum += p[j][countSameBitNum(i, f[j])];
    }
    if(i == 1) {
      ans = sum;
    }else{
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
