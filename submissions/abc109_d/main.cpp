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
const ll MOD=(ll)998244353;
//}}}

int a[501][501];
int ans[250000][4];
int main(){
  int H, W;
  cin >> H >> W;
  rep(h, H){
    rep(w, W){
      cin >> a[h][w];
    }
  }
  int ansNum = 0;
  rep(h, H){
    if(h % 2 == 0){
      rep(w, W){
        if(h == H - 1 && w == W - 1) continue;
        if(a[h][w] % 2){
          ans[ansNum][0] = h;
          ans[ansNum][1] = w;
          if(w == W - 1){
            ans[ansNum][2] = h + 1;
            ans[ansNum][3] = w;
          }else{
            ans[ansNum][2] = h;
            ans[ansNum][3] = w + 1;
          }
          a[ans[ansNum][2]][ans[ansNum][3]]++;
          /*
          printf("[%d %d] ", h, w);
          printf(" %d %d %d %d\n", ans[ansNum][0] + 1, ans[ansNum][1] + 1, ans[ansNum][2] + 1, ans[ansNum][3] + 1);
          */
          ansNum++;
        }
      }
    }else{
      rrep(w, W){
        if(h == H - 1 && w == 0) continue;
        if(a[h][w] % 2){
          ans[ansNum][0] = h;
          ans[ansNum][1] = w;
          if(w == 0){
            ans[ansNum][2] = h + 1;
            ans[ansNum][3] = w;
          }else{
            ans[ansNum][2] = h;
            ans[ansNum][3] = w - 1;
          }
          a[ans[ansNum][2]][ans[ansNum][3]]++;
          /*
          printf("[%d %d] ", h, w);
          printf(" %d %d %d %d\n", ans[ansNum][0] + 1, ans[ansNum][1] + 1, ans[ansNum][2] + 1, ans[ansNum][3] + 1);
          */
          ansNum++;
        }
      }
    }
  }
  cout << ansNum << endl;
  rep(i, ansNum){
    printf("%d %d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2] + 1, ans[i][3] + 1);
  }
  return 0;
}
