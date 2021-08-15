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

int main(){
  ll T1, T2;
  cin >> T1 >> T2;
  ll A1, A2;
  cin >> A1 >> A2;
  ll B1, B2;
  cin >> B1 >> B2;

  if(A1 * T1 + A2 * T2 == B1 * T1 + B2 * T2){
    cout << "infinity" << endl;
    return 0;
  }

  // A1が小さい(遅い)方を高橋君にする。
  if(A1 > B1){
    swap(A1, B1);
    swap(A2, B2);
  }

  ll T = T1 + T2;
  ll FA = A1 * T1;
  ll FB = B1 * T1;
  ll A = A1 * T1 + A2 * T2;
  ll B = B1 * T1 + B2 * T2;

  // 高橋君の逆転の可能性がないと0
  if(A < B){
    cout << 0 << endl;
    return 0;
  }

  ll N = (FB - FA) / (A - B);

  ll ans = 2 * N;
  if((FB - FA) % (A - B) != 0){
    ans++;
  }
  cout << ans << endl;
  return 0;
}
