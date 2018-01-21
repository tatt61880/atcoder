#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define Rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PrintLn(X) cout << X << endl
int main(void)
{
	int H, W;
	cin >> H >> W;
	char ans[103][103] = {0};
	Rep(h, H){
		char str[103];
		cin >> str;
		ans[h + 1][0] = '#';
		Rep(w, W){
			ans[h + 1][w + 1] = str[w];
		}
		ans[h + 1][W + 1] = '#';
	}
	Rep(w, W + 2){
		ans[0][w] = '#';
		ans[H + 1][w] = '#';
	}
	Rep(h, H + 2){
		PrintLn(ans[h]);
	}
	return 0;
}
