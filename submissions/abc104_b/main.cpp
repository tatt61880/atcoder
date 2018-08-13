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

int main(){
  char S[11];
  cin >> S;
  bool ans = true;

  if(S[0] != 'A') ans = false;
  bool f = true;
  int N = strlen(S);
  rep(i, 1, N){
    if(isupper(S[i])){
      if(f && i != 1 && i != N - 1 && S[i] == 'C'){
        f = false;
      }else{
        ans = false;
      }
    }
  }
  if(f) ans = false;

  puts(ans ? "AC" : "WA");
  return 0;
}
