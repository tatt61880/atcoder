#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
LL cost[10][10];
class Point{
	public:
		int x, y;
		Point(int x, int y): x(x), y(y){}
		bool operator<(const Point &p) const{
			return cost[x][y] > cost[p.x][p.y];
		}
};
int main(void)
{
	int H, W;
	cin >> H >> W;
	LL T;
	cin >> T;
	Point S(0, 0);
	Point G(0, 0);
	bool isWall[10][10];
	Rep(y, H){
		string buf;
		cin >> buf;
		Rep(x, W){
			isWall[x][y] = (buf[x] == '#');
			switch(buf[x]){
				case 'S': S.x = x; S.y = y; break;
				case 'G': G.x = x; G.y = y; break;
			}
		}
	}
	LL lo, hi;
	lo = 1;
	hi = T;
	while(lo < hi - 1){
		LL mi = (lo + hi) / 2;
		//PrintLn("mi = " << mi);
		vector<Point> v;
		Rep(y, H){
			Rep(x, W){
				cost[x][y] = -1;
			}
		}
		v.push_back(S);
		cost[S.x][S.y] = 0;
		while(!v.empty()){
			sort(v.begin(), v.end());
			Point p = v.back();
			//PrintLn("p(" << p.x << "," << p.y << ")[" << cost[p.x][p.y] << "]");
			v.pop_back();
			int d[5] = {1, 0, -1, 0, 1};
			Rep(i, 4){
				int tx = p.x + d[i];
				int ty = p.y + d[i + 1];
				if(tx < 0 || W <= tx) continue;
				if(ty < 0 || H <= ty) continue;
				LL tc = cost[p.x][p.y] + (isWall[tx][ty] ? mi : 1);
				//PrintLn("tc = " << tc);
				if(cost[tx][ty] == -1){
					v.push_back(Point(tx, ty));
					cost[tx][ty] = tc;
				}else{
					cost[tx][ty] = min(cost[tx][ty], tc);
				}
				//PrintLn("t(" << tx << "," << ty << ") cost=" << cost[tx][ty]);
			}
		}
		//PrintLn("lo=" << lo << " hi= " << hi << " mi=" << mi << " cost=" << cost[G.x][G.y]);
		((cost[G.x][G.y] <= T) ? lo : hi) = mi;
	}
	PrintLn(lo);
	return 0;
}
