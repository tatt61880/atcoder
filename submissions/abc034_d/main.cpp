#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PrintLn(X) cout << X << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

typedef struct {
	double w;
	double p;
	double s;
} Water;

int N, K;
vector<Water> v;

bool operator<(const Water& left, const Water& right) {
	return left.s < right.s;
}

bool solve(double p)
{
	for(auto& x: v){
		x.s = x.w * (x.p - p);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	double sum = 0;
	rep(i, K){
		sum += v[i].s;
	}
	return sum >= 0;
}


int main(void)
{
	cin >> N >> K;
	rep(i, N){
		double w, p;
		cin >> w >> p;
		v.push_back({w, p, 0});
	}

	double hi = 100.0;
	double lo = 0.0;
	double mi;
	while(hi - lo > 0.0000001){
		mi = (hi + lo) / 2.0;
		if(solve(mi)){
			lo = mi;
		}else{
			hi = mi;
		}
	}
	printf("%0.9lf\n", lo);
	return 0;
}
