#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

#define MAX 100
int main(void)
{
	int H, W, K;
	cin >> H >> W >> K;
	int k = 0;
	char c[MAX][MAX];
	rep(h, H) rep(w, W){
		if(k < K && h % 2 == 0 &&
 w % 2 == 0){
			k++;
			c[h][w] = '#';
		}else{
			c[h][w] = '.';
		}
	}
	if(k < K){
		cout << "IMPOSSIBLE" << endl;
	}else{
		rep(h, H){
			rep(w, W) cout << c[h][w];
			cout << endl;
		}
	}
	return 0;
}
