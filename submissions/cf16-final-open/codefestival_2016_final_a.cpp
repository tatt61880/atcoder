//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define rrep(...) repN((__VA_ARGS__,rrep3,rrep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,begin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
using ll=long long;
const ll MOD = (ll)1e9+7;
//}}}

int main(){
  int H, W;
  cin >> H >> W;
  rep(h, H) rep(w, W){
    string s;
    cin >> s;
    if(s == "snuke"){
      printf("%c%d\n", 'A' + w, h + 1);
    }
  }
  return 0;
}
