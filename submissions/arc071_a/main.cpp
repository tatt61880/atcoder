//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,b
egin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const ll MOD = 1e9+7;
//}}}

int main(){
  int n;
  cin >> n;
  string s;
  int alpha[26] = {0};
  cin >> s;
  rep(i, s.size()){
    alpha[s[i] - 'a']++;
  }
  rep(x, n - 1){
    int alphaTmp[26] = {0};
    cin >> s;
    rep(i, s.size()){
      alphaTmp[s[i] - 'a']++;
    }
    rep(i, 26){
      alpha[i] = min(alpha[i], alphaTmp[i]);
    }
  }
  rep(i, 26){
    rep(j, alpha[i]) printf("%c", i + 'a');
  }
  cout << endl;
  return 0;
}
