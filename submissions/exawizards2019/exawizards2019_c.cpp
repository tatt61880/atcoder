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

bool check(string &s, int Q, int N, int pos, vector<char> &t, vector<char> &d, bool left_check)
{
  char c = s[pos];
  rep(i, Q){
    if(t[i] == c){
      pos += d[i] == 'L' ? -1 : 1;
      if(pos < 0) return left_check ^ true;
      if(pos >= N) return left_check ^ false;
      c = s[pos];
    }
  }
  return true;
}

int main()
{
  int N, Q;
  string s;
  cin >> N >> Q;
  cin >> s;
  vector<char> t(Q);
  vector<char> d(Q);
  rep(i, Q){
    cin >> t[i] >> d[i];
  }
  int ans = N;
  {
    int ok = N;
    int ng = -1;
    while(ok - ng > 1){
      int mid = (ok + ng) / 2;
      (check(s, Q, N, mid, t, d, true) ? ok : ng) = mid;
    }
    ans -= ng + 1;
  }
  {
    int ok = -1;
    int ng = N;
    while(ng - ok > 1){
      int mid = (ok + ng) / 2;
      (check(s, Q, N, mid, t, d, false) ? ok : ng) = mid;
    }
    ans -= N - ng;
  }
  cout << ans << endl;
  return 0;
}
