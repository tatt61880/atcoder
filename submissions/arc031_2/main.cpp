#include <iostream>
#include <queue>
using namespace std;
#define PrintLn(X) cout << (X) << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	char A[10][10];
	char B[10][10];
	Rep(y, 10) Rep(x, 10) cin >> A[y][x];
	bool all_o_flag = true;
	typedef struct{
		int x;
		int y;
	} xy;
	Rep(y, 10) Rep(x, 10) {
		if(A[y][x] == 'o') continue;
		all_o_flag = false;
		Rep(y2, 10) Rep(x2, 10) B[y2][x2] = A[y2][x2];
		
		queue<xy> qu;
		qu.push({x, y});
		while(!qu.empty()){
			xy p = qu.front();
			qu.pop();
			if(p.x > 0 && B[p.y][p.x - 1] == 'o') B[p.y][p.x - 1] = 'x', qu.push({p.x - 1, p.y});
			if(p.x < 9 && B[p.y][p.x + 1] == 'o') B[p.y][p.x + 1] = 'x', qu.push({p.x + 1, p.y});
			if(p.y > 0 && B[p.y - 1][p.x] == 'o') B[p.y - 1][p.x] = 'x', qu.push({p.x, p.y - 1});
			if(p.y < 9 && B[p.y + 1][p.x] == 'o') B[p.y + 1][p.x] = 'x', qu.push({p.x, p.y + 1});
		}
		bool flag = true;
		Rep(y2, 10) Rep(x2, 10) if(B[y2][x2] == 'o') flag = false;
		if(flag) {
			PrintLn("YES");
			return 0;
		}
	}
	PrintLn(all_o_flag ? "YES" : "NO");
	return 0;
}
