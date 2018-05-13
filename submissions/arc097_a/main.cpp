//{{{
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
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
vector<string> ss;
int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  set<string> st;
  rep(i, s.size()){
    int r = s.size() - i;
    rep(j, 1, min(5, r) + 1){
      st.insert(s.substr(i, j));
    }
  }
  for(auto it = st.begin(); it != st.end(); it++){
    K--;
    if(K == 0){
      cout << (*it) << endl;
      return 0;
    }
  }
  return 0;
}
