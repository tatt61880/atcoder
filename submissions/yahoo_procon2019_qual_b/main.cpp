//{{{
#include <bits/stdc++.h>
using namespace std;
#define repX(a,b,child,x,...) x
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

int main(){
  map<int, int> mp;
  rep(i, 6){
    int a;
    cin >> a;
    mp[a]++;
  }
  bool ans = true;
  rep(i, 1, 5){
    if(mp[i] > 2) ans = false;
  }
  puts(ans ? "YES" : "NO");
  return 0;
}
