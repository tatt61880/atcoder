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
const int MOD = 1e9+7;
//}}}

int main(){
  int N, M, X;
  cin >> N >> M >> X;
  set<int> st;
  rep(i, M){
    int A;
    cin >> A;
    st.insert(A);
  }
  int a = 0;
  int b = 0;
  rep(i, 1, X + 1) if(st.count(i)) a++;
  rep(i, X, N) if(st.count(i)) b++;
  cout << (min(a, b)) << endl;
  return 0;
}
