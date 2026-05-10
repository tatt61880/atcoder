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

int nums[15];

int f(int n){
  n--;
  int res = 0;
  rep(i, 15){
    if(nums[i] >= n) res++;
  }
  return res;
}

int main(){
  int N;
  cin >> N;
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  rep(n, 2, N + 1){
    int num = n;
    rep(i, 15){
      while(num % primes[i] == 0){
        num /= primes[i];
        nums[i]++;
      }
    }
  }
  int num3 = f(3);
  int num5 = f(5);
  int num15 = f(15);
  int num25 = f(25);
  int num75 = f(75);
  int ans = 0;
  ans += num5 * (num5 - 1) / 2 * (num3 - 2);
  ans += num25 * (num3 - 1);
  ans += num15 * (num5 - 1);
  ans += num75;
  cout << ans << endl;
  return 0;
}
