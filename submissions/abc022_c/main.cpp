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
	int N, M;
	cin >> N >> M;
	int C[300][300] = {0};
	Rep(i, M){
		int u, v, l;
		cin >> u >> v >> l;
		C[u - 1][v - 1] = l;
		C[v - 1][u - 1] = l;
	}
	int m = -1;
	Rep(i, N){
		if(C[0][i] == 0) continue;
		Rep(j, N) cost[j] = -1;
		vector<int> v;
		v.push_back(i);
		cost[i] = C[0][i];
		while(!v.empty()){
			sort(v.begin(), v.end(), sort_func);
			int id = v.back();
			v.pop_back();
			Rep(j, N){
				if(id == i && j == 0) continue;
				if(j == id) continue;
				if(!C[id][j]) continue;
				int ct = cost[id] + C[id][j];
				if(cost[j] == -1){
					v.push_back(j);
					cost[j] = ct;
				}else if(cost[j] > ct){
					cost[j] = ct;
				}
			}
		}
		if(m == -1){
			m = cost[0];
		}else{
			m = min(m, cost[0]);
		}
	}
	PrintLn(m);
	return 0;
}
