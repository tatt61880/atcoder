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
const ll mod=(ll)1e9+7;
//}}}

bool f(string s){
  rep(i, s.size()){
    bool f = true;
    rep(j, 4){
      if(s[i] == "ACGT"[j]) f = false;
    }
    if(f) return false;
  }
  return true;
}

int main(){
  string s;
  cin >> s;
  int ans = 0;
  rep(i, s.size()){
    rep(j, i, s.size() + 1){
      string str = s.substr(i, j - i);
      if(f(str)){
        ans = max(ans, j - i);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
