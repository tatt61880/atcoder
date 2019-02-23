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
#define rrep3(i,begin,
end) for(int i=(int)(begin-1),i##_end=(int)(end);i>=i##_end;--i)
#define foreach(x,a) for(auto&x:a)
using ll=long long;
const ll mod=(ll)1e9+7;
//}}}

bool f(int n){
  bool flag3 = false;
  bool flag5 = false;
  bool flag7 = false;
  while(n){
    switch(n % 10){
      case 3: flag3 = true; break;
      case 5: flag5 = true; break;
      case 7: flag7 = true; break;
    }
    n /= 10;
  }
  return flag3 && flag5 && flag7;
}

int main(){
  int N;
  cin >> N;
  vector<int> v = {3, 5, 7};
  vector<int> temp1 = {3, 5, 7};
  rep(i, 9){
    vector<int> temp2;
    for(auto &x: temp1){
      temp2.push_back(x * 10 + 3);
      temp2.push_back(x * 10 + 5);
      temp2.push_back(x * 10 + 7);
    }
    temp1 = temp2;
    for(auto &x: temp1){
      v.push_back(x);
    }
  }

  int ans = 0;
  for(auto &x: v){
    if(x <= N && f(x)) ans++;
  }
  cout << ans << endl;
  return 0;
}
