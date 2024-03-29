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

ll a[31];
ll m[31];

bool f(ll n){
  rep(i, 2, 31){
    ll N = n;
    int sum = 0;
    while(N){
      sum += N % i;
      N /= i;
    }
    if(sum != a[i]) return false;
  }
  return true;
}

int main(){
  rep(i, 2, 30 + 1){
    cin >> a[i];
    m[i - 1] = a[i] % (i - 1);
  }

  vector<ll> v = {3, 5, 7, 11, 13, 17, 19, 23, 29};
  ll fact = 2;
  ll md = m[2];
  for(auto &x: v){
    ll mdNew = -1;
    for(ll i = md; i < fact * x; i += fact){
      if(i % x != m[x]) continue;
      mdNew = i;
      break;
    }
    if(mdNew == -1){
      cout << "invalid" << endl;
      return 0;
    }
    md = mdNew;
    fact *= x;
  }

  for(ll N = md; N <= (ll)1000000000000; N += fact){
    if(f(N)){
      cout << N << endl;
      return 0;
    }
  }
  cout << "invalid" << endl;
  return 0;
}
