#include <iostream>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int H, W;
char m[100][100];
int sub(int h, int w)
{
	if(h < 0) return 0;
	if(w < 0) return 0;
	if(h >= H) return 0;
	if(w >= W) return 0;
	if(m[h][w] == '#') return 1;
	return 0;
}
int count(int h, int w)
{
	int res = 0;
	Rep(i, 3){
		Rep(j, 3){
			if(i != 1 || j != 1){
				res += sub(h + i - 1, w + j - 1);
			}
		}
	}
	return res;
}
int main(void)
{
	cin >> H >> W;
	Rep(h, H) cin >> m[h];
	Rep(h, H){
		Rep(w, W){
			if(m[h][w] == '.'){
				m[h][w] = count(h, w) + '0';
			}
		}
	}
	Rep(h, H) PrintLn(m[h]);
	return 0;
}
