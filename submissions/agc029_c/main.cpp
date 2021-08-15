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

int N;
int a[200000];
map<int, int> mp;

bool f(int n){
  mp.clear();
  mp[a[0]] = 0;
  rep(i, 1, N){
    if(a[i] <= a[i - 1]){
      int pos = a[i];
      {
        auto it = mp.find(pos);
        if(it == mp.end()){
          mp[pos] = 0;
        }
      }
      {
        auto it = mp.find(pos);
        auto itt = mp.end();
        for(itt--; itt != it; itt--){
          mp.erase(itt);
        }
      }
      {
        while(mp[pos] == n - 1){
          mp[pos] = 0;
          pos--;
        }
        if(pos == 0){
          return false;
        }
        mp[pos]++;
      }
    }
  }
  return true;
}

int main(){
  cin >> N;
  rep(i, N) scanf("%d", &a[i]);
  {
    bool flag = true;
    rep(i, 1, N){
      if(a[i] <= a[i - 1]){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << 1 << endl;
      return 0;
    }
  }

  int hi = N;
  int lo = 1;
  while(hi - lo > 1){
    int mi = (hi + lo) / 2;
    if(f(mi)){
      hi = mi;
    }else{
      lo = mi;
    }
  }
  cout << hi << endl;
  return 0;
}
