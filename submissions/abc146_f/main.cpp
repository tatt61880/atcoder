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
int dp[100001];
int main(){
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  stack<int> st;
  st.push(N);
  dp[N] = 1;
  while(st.size()){
    int pos = st.top();
    st.pop();
    bool flag = true;
    rrep(i, M + 1, 1){
      int next = pos - i;
      if(next < 0) continue;
      if(S[next] == '0') {
        dp[next] = i;
        flag = false;
        if(next != 0) st.push(next);
        break;
      }
    }
    if(flag){
      cout << -1 << endl;
      return 0;
    }
  }
  int pos = 0;
  while(1){
    int ans = dp[pos];
    pos += ans;
    cout << ans;
    if(pos == N){
      cout << endl;
      break;
    }else{
      cout << " ";
    }
  }
  return 0;
}
