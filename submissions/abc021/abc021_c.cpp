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

int cost[100];
bool sort_func(const int a, const int b){
    return cost[a] > cost[b];
}

int main(void)
{
	int N;
	cin >> N;
	int a, b;
	cin >> a >> b;
	int M;
	cin >> M;
	int C[100][100] = {0};
	int count[100] = {0};
	Rep(i, N) cost[i] = -1;
	Rep(i, M){
		int x, y;
		cin >> x >> y;
		C[x - 1][y - 1] = 1;
		C[y - 1][x - 1] = 1;
	}
	LL ans = 0;
	vector<int> v;
	a--;
	cost[a] = 0;
	count[a] = 1;
	v.push_back(a);
	while(!v.empty()){
		sort(v.begin(), v.end(), sort_func);
		int id = v.back();
		v.pop_back();
		Rep(i, N){
			if(i == id) continue;
			if(!C[id][i]) continue;
			if(cost[i] == -1){
				v.push_back(i);
				cost[i] = cost[id] + 1;
				count[i] = count[id];
			}else{
				if(cost[i] == cost[id] + 1){
					count[i] += count[id];
					count[i] %= MOD;
				}else if(cost[i] > cost[id] + 1){
					cost[i] = cost[id] + 1;
					count[i] = count[id];
				}
			}
		}
	}

	PrintLn(count[b - 1]);
	return 0;
}
