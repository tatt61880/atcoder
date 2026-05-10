#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef struct{
	//int black; //自分自身が黒の場合の場合の数
	ll white; //自分自身が白の場合の場合の数
	ll total; //black+white
} Count;
vector<int> v[100000];
// aに対し、exception側が存在しないものとみなしたCountを返す関数。

Count f(int a, int exception){
	ll w = 1;
	ll t = 1;
	for(vector<int>::iterator it = v[a].begin(); it != v[a].end(); ++it){
		if(*it == exception) continue;
		Count c = f(*it, a);
		w = (w * c.white) % MOD;
		t = (t * c.total) % MOD;
	}
	return {t, ((w + t) % MOD)};
}
int main(void)
{
	int N;
	cin >> N;
	Rep(i, N - 1){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	Count c = f(1, 0);
	PrintLn(c.total);
	return 0;
}
