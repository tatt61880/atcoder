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

typedef long long 
LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void){
	int H, W;
	cin >> H >> W;
	int C[100][100];
	Rep(h, H)Rep(w, W) cin >> C[h][w], ((h + w) % 2) ? C[h][w] *= -1 : 0;
	int D[101][101] = {0};
	Rep(h, H+1)Rep(w, W+1) D[h][w] = (h == 0 || w == 0) ? 0 : D[h][w-1] + D[h-1][w] - D[h-1][w-1] + C[h-1][w-1];
	int ans = 0;
	Rep(h1, H+1)Rep(w1, W+1)Rep(h2, h1)Rep(w2, w1) if(D[h1][w1] - D[h1][w2] - D[h2][w1] + D[h2][w2] == 0) ans = max(ans, (h1-h2)*(w1-w2));
	PrintLn(ans);
	return 0;
}
