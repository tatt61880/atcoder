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

char A[1001][1001];
int H, W;

bool f(int x, int y){
  if(x < 0) return 0;
  if(y < 0) return 0;
  if(x >= W) return 0;
  if(y >= H) return 0;
  return (A[y][x] == '.');
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
  cin >> H >> W;

  rep(i, H){
    cin >> A[i];
  }

  int count = 0;
  stack<pair<int, int>> st;
  rep(h, H){
    rep(w, W){
      if(A[h][w] == '#'){
        st.push(make_pair(h, w));
        count++;
      }
    }
  }

  int ans = 0;
  while(count != H * W){
    ans++;
    stack<pair<int, int>> st2;
    while(st.size()){
      pair<int, int> p = st.top();
      st.pop();
      int y = p.first;
      int x = p.second;
      rep(i, 4){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(f(xx, yy)){
          A[yy][xx] = '#';
          count++;
          st2.push(make_pair(yy, xx));
        }
      }
    }
    st = st2;
  }

  cout << ans << endl;
  return 0;
}
