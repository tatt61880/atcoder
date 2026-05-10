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
const ll MOD = 998244353;
//}}}

int a[100];
int main(){
  int N;
  cin >> N;
  rep(i, N){
    cin >> a[i];
  }
  sort(a, a + N);
  reverse(a, a + N);
  int A, B;
  rep(i, N){
    (i % 2 == 0 ? A : B) += a[i];
  }
  int ans = A - B;
  cout << ans << endl;
  return 0;
}
