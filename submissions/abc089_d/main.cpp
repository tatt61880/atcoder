//{{{
#include <bits/stdc++.h>
using namespace std;
#define rep(...) repN((__VA_ARGS__,rep3,rep2,loop,~))(__VA_ARGS__)
#define loop(n) rep2(_loop_,n)
#define rep2(i,n) rep3(i,0,n)
#define rep3(i,begin,end) for(int i=(int)(begin),i##_end=(int)(end);i<i##_end;++i)
#define repN(a) repX a
#define repX(a0,a1,a2,x,...) x
typedef long long ll;
const int MOD = 1e9+7;
//}}}

int cost[100000];
int main(){
	int H, W, D;
	cin >> H >> W >> D;

	map<int, pair<int, int>> m;
	rep(h, H){
		rep(w, W){
			int a;
			cin >> a;
			m[a] = make_pair(h, w);
		}
	}

	rep(d, D){
		int prev_h = 0;
		int prev_w = 0;
		for(int i = d; i < H * W + 1; i += D){
			cost[i] = (i - D <= 0 ? 0 : cost[i - D]) + abs(m[i].first - prev_h) + abs(m[i].second - prev_w);
			prev_h = m[i].first;
			prev_w = m[i].second;
		}
	}
	int Q;
	cin >> Q;
	int ans = 0;
	rep(q, Q){
		int l, r;
		cin >> l >> r;
		cout << (cost[r] - cost[l]) << endl;
	}
	return 0;
}
