//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#defi
ne rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const ll MOD = 1e9+7;
//}}}

string s[2000];
int r[2000][2000];
int l[2000][2000];
int t[2000][2000];
int b[2000][2000];
int main(){
  int N, M;
  cin >> N >> M;
  rep(i, N) cin >> s[i];

  rep(n, N){
    rep(m, M){
      if(m == 0 || s[n][m] == '#'){
        l[n][m] = 0;
      }else{
        if(s[n][m-1] == '.'){
          l[n][m] = l[n][m-1] + 1;
        }else{
          l[n][m] = 0;
        }
      }
      if(m == 0 || s[n][M-1-m] == '#'){
        r[n][M-1-m] = 0;
      }else{
        if(s[n][M-m] == '.'){
          r[n][M-1-m] = r[n][M-m] + 1;
        }else{
          r[n][M-1-m] = 0;
        }
      }
    }
  }
  rep(m, M){
    rep(n, N){
      if(n == 0 || s[n][m] == '#'){
        t[n][m] = 0;
      }else{
        if(s[n-1][m] == &#3
9;.'){
          t[n][m] = t[n-1][m] + 1;
        }else{
          t[n][m] = 0;
        }
      }
      if(n == 0 || s[N-1-n][m] == '#'){
        b[N-1-n][m] = 0;
      }else{
        if(s[N-n][m] == '.'){
          b[N-1-n][m] = b[N-n][m] + 1;
        }else{
          b[N-1-n][m] = 0;
        }
      }
    }
  }
  /*
  rep(n, N){
    rep(m, M){
      printf("%d", l[n][m]);
    }
    printf("\n");
  }
  printf("--\n");
  rep(n, N){
    rep(m, M){
      printf("%d", r[n][m]);
    }
    printf("\n");
  }
  */
  ll ans = 0;
  rep(n, N){
    rep(m, M){
      ans += r[n][m] * t[n][m];
      ans += t[n][m] * l[n][m];
      ans += l[n][m] * b[n][m];
      ans += b[n][m] * r[n][m];
    }
  }
  cout << ans << endl;
  return 0;
}
