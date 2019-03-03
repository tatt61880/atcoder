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
const ll MOD=(ll)998244353;
//}}}
int digitSum(ll n){
  int res = 0;
  while(n){
    res += n % 10;
    n /= 10;
  }
  return res;
}
int digit(ll n){
  int res = 0;
  do{
    res++;
    n /= 10;
  }while(n);
  return res;
}
int f(ll n){
  int res = 0;
  while(n){
    res = n % 10;
    n /= 10;
  }
  return res;
}
int main(){
  ll N;
  cin >> N;
  ll ans;
  if(digitSum(N) == 1){
    if(N == 1){
      ans = 1;
    }else{
      ans = (digit(N) - 1) * 9;
    }
  }else{
    ans = max(digitSum(N), f(N) - 1 + (digit(N) - 1) * 9);
  }
  cout << ans << endl;
  return 0;
}
