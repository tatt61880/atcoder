//{{{
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
const int MOD = 1e9+7;
//}}}

typedef pair<int,int> PII;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue<PII> q;
int H, W;
char s[51][51];
int dist[51][51];

void f(int x, int y, int num){
	if(x < 0 || W <= x) return;
	if(y < 0 || H <= y) return;
	if(s[y][x] == '.' && dist[y][x] == 0){
		dist[y][x] = num + 1;
		q.emplace(x, y);
	}
}

int main(void){
	cin >> H >> W;
	rep(i, H) cin >> s[i];
	int total = 0;
	rep(i, H){
		rep(j, W){
			if(s[i][j] == '.') total++;
		}
	}

	q.emplace(0, 0);
	dist[0][0] = 1;
	while(!q.empty()){
		PII pos = q.front();
		q.pop();
		int x = pos.first;
		int y = pos.second;
		int num = dist[y][x];
		rep(i, 4) f(x + dx[i], y + dy[i], num);
	}
	if(dist[H - 1][W - 1] == 0){
		puts("-1");
	}else{
		printf("%d\n", total - dist[H - 1][W - 1]);
	}
	return 0;
}
