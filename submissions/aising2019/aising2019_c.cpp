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

typedef struct {
  int h;
  int w;
} Pos;

char m[400][400];
int main(){
  int H, W;
  cin >> H >> W;
  rep(h, H){
    cin >> m[h];
  }
  ll ans = 0;
  rep(h, H){
    rep(w, W){
      int sH = h;
      int sW = w;
      char c = m[sH][sW];
      if(c == ' ') continue;
      ll countB = 0;
      ll countW = 0;
      queue<Pos> qu;
      Pos p = {sH, sW};
      qu.push(p);
      while(qu.size()){
        Pos p = qu.front();
        qu.pop();
        int x = p.w;
        int y = p.h;
        if(m[y][x] == ' ') continue;
        if(m[y][x] == '#') countB++;
        if(m[y][x] == '.') countW++;
        //cout << "x = " << x << " y = " << y << endl;
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        rep(i, 4){
          int xx = x + dx[i];
          int yy = y + dy[i];
          if(xx < 0) continue;
          if(yy < 0) continue;
          if(xx >= W) continue;
          if(yy >= H) continue;
          if(m[yy][xx] == ' ') continue;
          if(m[yy][xx] != m[y][x]){
            Pos p = {yy, xx};
            qu.push(p);
          }
        }
        m[y][x] = ' ';
      }
      //cout << "countB = " << countB;
      //cout << " countW = " << countW << endl;
      ans += countB * countW;
    }
  }
  cout << ans << endl;
  return 0;
}
