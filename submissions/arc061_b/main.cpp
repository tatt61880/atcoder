#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int a[100000];
int b[100000];
set<pair<int, int>> st;

LL H, W, N;
int exist(int a, int b){
	return (1 <= a && a <= H && 1 <= b && b <= W && st.count(pair<int, int>(a, b)));
}

int cou[9];

int main(void)
{
	LL ans[10] = {0};
	cin >> H >> W >> N;
	LL total = (H - 2) * (W - 2);

	Rep(i, N){
		cin >> a[i] >> b[i];
		st.insert(pair<int, int>(a[i], b[i]));
	}
	Rep(i, N){
		// xxx
		// xox
		// xxx
		Rep(x, 9){
			cou[x] = 0;
		}
		Rep(di, 5){
			Rep(dj, 5){
				if(exist(a[i] - 2 + di, b[i] - 2 + dj)){
					if(           di <= 2 &&            dj <= 2) cou[0]++;
					if(1 <= di && di <= 3 &&            dj <= 2) cou[1]++;
					if(2 <= di            &&            dj <= 2) cou[2]++;
					if(           di <= 2 && 1 <= dj && dj <= 3) cou[3]++;
					if(1 <= di && di <= 3 && 1 <= dj && dj <= 3) cou[4]++;
					if(2 <= di            && 1 <= dj && dj <= 3) cou[5]++;
					if(           di <= 2 && 2 <= dj           ) cou[6]++;
					if(1 <= di && di <= 3 && 2 <= dj           ) cou[7]++;
					if(2 <= di            && 2 <= dj           ) cou[8]++;
				}
			}
		}
		if(a[i] == 1) cou[0] = cou[1] = cou[3] = cou[4] = cou[6] = cou[7] = 0;
		if(b[i] == 1) cou[0] = cou[1] = cou[2] = cou[3] = cou[4] = cou[5] = 0;
		if(a[i] == 2) cou[0] = cou[3] = cou[6] = 0;
		if(b[i] == 2) cou[0] = cou[1] = cou[2] = 0;
		if(a[i] == H) cou[1] = cou[2] = cou[4] = cou[5] = cou[7] = cou[8] = 0;
		if(b[i] == W) cou[3] = cou[4] = cou[5] = cou[6] = cou[7] = cou[8] = 0;
		if(a[i] == H - 1) cou[2] = cou[5] = cou[8] = 0;
		if(b[i] == W - 1) cou[6] = cou[7] = cou[8] = 0;
		Rep(x, 9){
			if(cou[x])ans[cou[x]]++;
		}
	}

	For(i, 1, 10){
		ans[i] /= i;
	}

	ans[0] = total;
	For(i, 1, 10){
		ans[0] -= ans[i];
	}
	Rep(i, 10){
		PrintLn(ans[i]);
	}
	return 0;
}
