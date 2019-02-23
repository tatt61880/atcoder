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
#define rrep3(i,begin,end) for(int i=(in
t)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

int a[200000];
map<int, int> mp;

int target[32];

int f(int n){
  rep(i, 32){
    int num = target[i] - n;
    if(num > n) continue;
    if(num < 0) continue;
    if(n != num && mp[n] && mp[num] ||
        n == num && mp[n] >= 2
        ){
      //cout << n << " "<< num << endl;
      mp[n]--;
      mp[num]--;
      return 1;
    }
  }
  return 0;
}

int main(){
  int N;
  cin >> N;
  target[0] = 1;
  rep(i, 1, 32){
    target[i] = target[i - 1] * 2;
  }
  rep(i, N){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a, a + N);
  reverse(a, a + N);
  ll ans = 0;
  rep(i, N){
    ans += f(a[i]);
  }
  cout << ans << endl;
  return 0;
}
