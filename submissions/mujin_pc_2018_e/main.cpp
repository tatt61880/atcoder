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
const ll MOD = 1e9+7;
//}}}
string s[1000];
ll ans[1000][1000];
string d;
int U[100000];
int D[100000];
int L[100000];
int R[100000];
typedef struct {
  int x;
  int y;
} Pos;
int N, M, K;
int isValid(int x, int y){
  if(x < 0) return false;
  if(x >= M) return false;
  if(y < 0) return false;
  if(y >= N) return false;
  if(s[y][x] == '#') return false;
  return true;
}
int main(){
  cin >> N >> M >> K;
  cin >> d;
  d += d;
  rep(i, N) cin >> s[i];
  int Sx;
  int Sy;
  int Gx;
  int Gy;
  rep(n, N){
    rep(m, M){
      ans[n][m] = -1;
      if(s[n][m] == 'S'){
        Sx = m;
        Sy = n;
        ans[n][m] = 0;
      }else if(s[n][m] == 'G'){
        Gx = m;
        Gy = n;
      }
    }
  }
  int lastU = -1;
  int lastD = -1;
  int lastL = -1;
  int lastR = -1;
  rep(i, 2 * K){
    switch(d[2 * K - 1 - i]){
    case 'U': lastU = 2 * K - 1 - i; break;
    case 'D': lastD = 2 * K - 1 - i; break;
    case 'L': lastL = 2 * K - 1 - i; break;
    case 'R': lastR = 2 * K - 1 - i; break;
    }
    if(i >= K){
      U[2 * K - 1 - i] = lastU == -1 ? -1 : lastU - (2 * K - 1 - i);
      D[2 * K - 1 - i] = lastD == -1 ? -1 : lastD - (2 * K - 1 - i);
      L[2 * K - 1 - i] = lastL == -1 ? -1 : lastL - (2 * K - 1 - i);
      R[2 * K - 1 - i] = lastR == -1 ? -1 : lastR - (2 * K - 1 - i);
    }
  }
#if 0
  cout << d << endl;
  rep(i, K){
    printf("%d %d %d %d\n", U[i], D[i], L[i], R[i]);
  }
#endif
  queue<Pos> qu;
  Pos p;
  p.x = Sx;
  p.y = Sy;
  qu.push(p);
  while(qu.size()){
    Pos p = qu.front();
    qu.pop();
    int x = p.x;
    int y = p.y;
    int i = ans[y][x] % K;
    if(isValid(x + 1, y) && R[i] != -1 && (ans[y][x + 1] == -1 || ans[y][x + 1] > ans[y][x] + R[i] + 1)) {ans[y][x + 1] = ans[y][x] + R[i] + 1; Pos t; t.x = x + 1; t.y = y; qu.push(t);}
    if(isValid(x - 1, y) && L[i] != -1 && (ans[y][x - 1] == -1 || ans[y][x - 1] > ans[y][x] + L[i] + 1)) {ans[y][x - 1] = ans[y][x] + L[i] + 1; Pos t; t.x = x - 1; t.y = y; qu.push(t);}
    if(isValid(x, y + 1) && D[i] != -1 && (ans[y + 1][x] == -1 || ans[y + 1][x] > ans[y][x] + D[i] + 1)) {ans[y + 1][x] = ans[y][x] + D[i] + 1; Pos t; t.x = x; t.y = y + 1; qu.push(t);}
    if(isValid(x, y - 1) && U[i] != -1 && (ans[y - 1][x] == -1 || ans[y - 1][x] > ans[y][x] + U[i] + 1)) {ans[y - 1][x] = ans[y][x] + U[i] + 1; Pos t; t.x = x; t.y = y - 1; qu.push(t);}
  }
#if 0
  rep(n, N){
    rep(m, M){
      printf("%2lld ", ans[n][m]);
    }
    printf("\n");
  }
#endif
  cout << ans[Gy][Gx] << endl;
  return 0;
}
