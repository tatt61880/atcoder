#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

int main(void)
{
	int N;
	cin >> N;
	map<ll, int> m;
	vector<ll> v;

	Rep(i, N){
		ll a;
		cin >> a;
		m[a]++;
	}
	for(auto x: m){
		if(x.second >= 2){
			v.push_back(x.first);
		}
	}

	ll ans = 0;
	if(v.size() > 0){
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		if(m[v[0]] >= 4){
			ans = v[0] * v[0];
		}else if(v.size() > 1){
			ans = v[0] * v[1];
		}
	}
	PrintLn(ans);
	return 0;
}
