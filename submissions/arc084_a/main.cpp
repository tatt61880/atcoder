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

int a[100000];
ll ab[100000];
int b[100000];
ll bc[100000];
int c[100000];
int main(){
  int N;
  cin >> N;
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  rep(i, N) cin >> c[i];
  sort(a, a + N);
  sort(b, b + N);
  sort(c, c + N);

  {
    int ai = 0;
    int bi = 0;
    while(1){
      if(a[ai] < b[bi]){
        ai++;
        if(ai == N){
          rep(i, bi, N){
            ab[i] = ai;
          }
          break;
        }
      }else{
        ab[bi] = ai;
        bi++;
        if(bi == N){
          break;
        }
      }
    }
  }
  {
    int bi = 0;
    int ci = 0;
    while(1){
      if(b[bi] < c[ci]){
        bc[bi] = N - ci;
        bi++;
        if(bi == N){
          break;
        }
      }else{
        ci++;
        if(ci == N){
          rep(i, bi, N){
            bc[i] = N - ci;
          }
          break;
        }
      }
    }
  }
  ll ans = 0;
  rep(i, N){
    ans += ab[i] * bc[i];
  }

  cout << ans << endl;
  return 0;
}
