//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
#define foreach(x,a) for(auto &x:a)
typedef long long ll;
const ll MOD = (ll)1e9+7;
//}}}

int A[200000];
int a[200001];
int main(){
  int N, K;
  cin >> N >> K;
  rep(i, N) cin >> A[i];
  rep(i, N){
    a[A[i]]++;
  }
  int count = 0;
  rep(i, N + 1){
    if(a[i] == 0){
      count++;
      a[i] = N + 1;
    }
  }
  sort(a, a + N + 1);
  int num = N + 1 - count - K;
  int ans = 0;
  rep(i, num){
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
