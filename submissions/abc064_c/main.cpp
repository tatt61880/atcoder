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

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
  int N;
  cin >> N;

  set<int> st;
  int x = 0;
  rep(i, N){
    int a;
    cin >> a;
    if(a < 3200){
      st.insert(a / 400);
    }else{
      x++;
    }
  }
  int ansMin = st.size();
  int ansMax = st.size();
  ansMax += x;
  if(ansMin == 0){
    ansMin = 1;
  }

  cout << ansMin << " " << ansMax << endl;
  return 0;
}
