#include <iostream>
#include <queue>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef struct{
	int w;
	int h;
} P;
char A[1000][1000];
int a[1000][1000] = {0};
int H, W, K;
int g(int w, int h)
{
	int ret = 1000;
	if(A[h][w] != 'T') return ret;
	if(h < ret) ret = h;
	if(w < ret) ret = w;
	if(H - h - 1 < ret) ret = H - h - 1;
	if(W - w - 1 < ret) ret = W - w - 1;
	return (ret + K - 1) / K;
}
int f(int w, int h)
{
	if(w <  0) return 0;
	if(w >= W) return 0;
	if(h <  0) return 0;
	if(h >= H) return 0;
	if(A[h][w] == '.'){
		A[h][w] = 'T';
		return 1;
	}
	return 0;
}
int main(void)
{
	cin >> H >> W >> K;
	P p;
	Rep(h, H){
		cin >> A[h];
		Rep(w, W){
			if(A[h][w] == 'S'){
				p.w = w;
				p.h = h;
				a[h][w] = 0;
				A[h][w] = 'T';
			}
		}
	}
	queue<P> qu;
	qu.push(p);
	while(!qu.empty()){
		p = qu.front();
		qu.pop();
		int w = p.w;
		int h = p.h;
		if(a[h][w] == K) continue;
		if(f(w-1, h)){a[h][w-1] = a[h][w] + 1; p.w = w-1; p.h = h; qu.push(p);}
		if(f(w+1, h)){a[h][w+1] = a[h][w] + 1; p.w = w+1; p.h = h; qu.push(p);}
		if(f(w, h-1)){a[h-1][w] = a[h][w] + 1; p.w = w; p.h = h-1; qu.push(p);}
		if(f(w, h+1)){a[h+1][w] = a[h][w] + 1; p.w = w; p.h = h+1; qu.push(p);}
	}
	int ans = 1000;
	Rep(h, H){
		Rep(w, W){
			int score = g(w, h);
			if(score < ans) ans = score;
		}
	}
	PrintLn(ans + 1);
	return 0;
}
