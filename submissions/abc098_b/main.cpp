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
const int MOD = 1e9+7;
//}}}

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  rep(i, N){
    set<char> st1;
    set<char> st2;
    rep(j, i){
      st1.insert(S[j]);
    }
    rep(j, i, N){
      st2.insert(S[j]);
    }
    int num = 0;
    for(auto x: st1){
      if(st2.count(x)) num++;
    }
    ans = max(ans, num);
  }
  cout << ans << endl;
  return 0;
}
