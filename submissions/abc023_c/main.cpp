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
const LL MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
typedef struct{
	int r;
	int c;
} Point;
int main(void)
{
	int R, C, K;
	cin >> R >> C >> K;
	int N;
	int col[100000]={0};
	int row[100000]={0};
	vector<Point> v;
	cin >> N;
	Rep(i, N){
		Point p;
		cin >> p.r >> p.c;
		p.r--;
		p.c--;
		v.push_back(p);
		row[p.r]++;
		col[p.c]++;
	}
	int cc[100001]={0};
	int rc[100001]={0};
	Rep(r, R){
		rc[row[r]]++;
	}
	Rep(c, C){
		cc[col[c]]++;
	}
	LL ans = 0;
	Rep(i, K + 1){
		ans += (LL)cc[i] * rc[K - i];
	}
	Rep(i, N){
		int num = row[v[i].r] + col[v[i].c];
		if(num == K) ans--;
		if(num == K + 1) ans++;
	}
	PrintLn(ans);
	return 0;
}
