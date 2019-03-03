#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(void)
{
	int N;
	cin >> N;
	vector<int> v;
	Rep(i, N){
		int n;
		cin >> n;
		v.push_back(n);
	}
	map<int, int> m;
	for(auto& x:v) m[x] = 0;
	int i = 0;
	for(auto& x:m) x.second = i++;
	for(auto& x:v) PrintLn(m[x]);
	return 0;
}
