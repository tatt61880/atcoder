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

ll digit(ll num){
  int res = 0;
  while(num){
    num /= 10;
    res++;
  }
  return res;
}

int main(){
  ll N;
  cin >> N;

  int num = 1;
  rep(i, 1, 100001){
    if(i * i > N) break;
    if(N % i == 0) num = i;
  }
  ll ans = max(digit(num), digit(N / num));
  cout << ans << endl;
  return 0;
}
