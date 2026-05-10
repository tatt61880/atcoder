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

string ids[100000];
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v;
  rep(i, M){
    int p, y;
    cin >> p >> y;
    vector<int> vv = {p, y, i};
    v.push_back(vv);
  }
  sort(v.begin(), v.end());
  int prev = -1;
  foreach(x, v){
    int a, b;
    a = x[0];
    if(prev != a){
      prev = a;
      b = 0;
    }
    b++;
    char buff[20];
    sprintf(buff, "%06d%06d", a, b);
    ids[x[2]] = buff;
  }
  rep(i, M){
    cout << ids[i] << endl;
  }
  return 0;
}
