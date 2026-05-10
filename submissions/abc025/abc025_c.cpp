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

int a[3][3];
int b[3][2];
int c[2][3];

int calc_score(int n){
	if(n == 9){
		int score = 0;
		Rep(x, 3) Rep(y, 2) if(a[x][y] == a[x][y+1]) score += b[x][y];
		Rep(x, 2) Rep(y, 3) if(a[x][y] == a[x+1][y]) score += c[x][y];
		return score;
	}
	if(n % 2){
		int min_score = -1;
		Rep(x, 3) Rep(y, 3){
			if(a[x][y] == -1){
				a[x][y] = 1;
				int score = calc_score(n+1);
				a[x][y] = -1;
				if(min_score == -1){
					min_score = score;
				}else{
					min_score = min(min_score, score);
				}
			}
		}
		return min_score;
	}else{
		int max_score = 0;
		Rep(x, 3) Rep(y, 3){
			if(a[x][y] == -1){
				a[x][y] = 0;
				int score = calc_score(n+1);
				a[x][y] = -1;
				max_score = max(max_score, score);
			}
		}
		return max_score;
	}
}

int main(void)
{
	int total_score = 0;
	Rep(y, 2) Rep(x, 3) {cin >> b[x][y]; total_score += b[x][y];}
	Rep(y, 3) Rep(x, 2) {cin >> c[x][y]; total_score += c[x][y];}
	Rep(x, 3) Rep(y, 3) a[x][y] = -1;

	int chokudaikun = calc_score(0);
	int naokosan = total_score - chokudaikun;

	PrintLn(chokudaikun);
	PrintLn(naokosan);
	return 0;
}
