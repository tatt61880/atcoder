//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,c,x,...) x
#define repN(a) repX a
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop))(__VA_ARGS__)
#define rrep(...) repN((__VA
_ARGS__,rrep3,rrep2))(__VA_ARGS__)
#define loop(n) rep2(i_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep3(i,begin,end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll MOD=(ll)998244353;
//}}}

int main(){
  set<string> st;
  int n;
  cin >> n;
  string cur;
  string bef;
  bool ans = true;
  rep(i, n){
    cin >> cur;
    st.insert(cur);
    if(i != 0){
      if(bef[bef.size()-1] != cur[0]) ans = false;
    }
    bef = cur;
  }
  if(st.size() != n) ans = false;
  puts(ans ? "Yes" : "No");
  return 0;
}
