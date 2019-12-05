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
int main(){
  int N;
  cin >> N;
  int ans = 0;
  int ba = 0;
  int a = 0;
  int b = 0;
  rep(i, N){
    string s;
    cin >> s;
    rep(i, s.size() - 1){
      if(s[i] == 'A' && s[i + 1] == 'B') ans++;
    }
    if(s[0] == 'B'){
      if(s[s.size() - 1] == 'A') ba++;
      else b++;
    }else if(s[s.size() - 1] == 'A') a++;
  }
  if(ba){
    if(a && b){
      a--;
      b--;
      ans += ba + 1;
      ans += min(a, b);
    }else if(a){
      ans += ba;
    }else if(b){
      ans += ba;
    }else{
      ans += ba - 1;
    }
  }else{
    ans += min(a, b);
  }
  cout << ans << endl;
  return 0;
}
