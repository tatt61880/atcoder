#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

typedef enum{
	NONE,
	WALL,
	FIRST,
	SECOND,
} STATE;

STATE S[101][101];

// (h, w)の位置から開始したときにどちらが勝つか。
STATE f(int h, int w)
{
	if(S[h][w] != NONE) return S[h][w];
	if(S[h+1][w] == WALL &a
mp;& S[h][w+1] == WALL && S[h+1][w+1] == WALL) return S[h][w] = SECOND;
	if(f(h+1, w) == SECOND || f(h, w+1) == SECOND || f(h+1, w+1) == SECOND) return S[h][w] = FIRST;
	return S[h][w] = SECOND;
}

int main(void)
{
	int H, W;
	cin >> H >> W;
	char C[100][100];
	Rep(h, H) Rep(w, W) cin >> C[h][w];
	Rep(h, H) Rep(w, W) S[h][w] = (C[h][w] == '#') ? WALL : NONE;
	Rep(h, H + 1) S[h][W] = WALL;
	Rep(w, W + 1) S[H][w] = WALL;
	PrintLn((f(0, 0) == FIRST ? "First" : "Second"));
	return 0;
}
