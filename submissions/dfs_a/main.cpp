#include <iostream>
#include <queue>
using namespace std;
#define PrintLn(X) cout << (X) << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
char c[500][500];
int H, W;
bool f(int x, int y){
	if(x == -1 || x == W) return false;
	if(y == -1 || y == H) return false;
	if(c[y][x] == 's') return false;
	if(c[y][x] == '#') return false;
	c[y][x] = 's';
	return true;
}
int main(void)
{
	cin >> H >> W;
	Rep(h, H) Rep(w, W) cin >> c[h][w];
	typedef struct{
		int x;
		int y;
	}Point;
	queue<Point> qu;
	Rep(h, H) Rep(w, W) if(c[h][w] == 's') qu.push({w, h});
	while(!qu.empty()){
		Point p = qu.front();
		qu.pop();
		int d[] = {1,0,-1,0,1};
		Rep(i, 4){
			if(f(p.x + d[i], p.y + d[i+1])) qu.push({p.x + d[i], p.y + d[i+1]});
		}
	}
	
	bool f = true;
	Rep(h, H) Rep(w, W) if(c[h][w] == 'g') f = false;
	PrintLn(f ? "Yes" : "No");
	return 0;
}
