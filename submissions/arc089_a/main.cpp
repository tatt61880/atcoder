#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define printLn(X) cout << X << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
int main(){
	int N;
	cin >> N;
	int tNow = 0;
	int xNow = 0;
	int yNow = 0;
	bool ans = true;
	rep(i, N){
		int tNext;
		int xNext;
		int yNext;
		cin >> tNext >> xNext >> yNext;
		int t = tNext - tNow;
		int d = abs(xNext - xNow) + abs(yNext - yNow);
		if(d <= t && (d - t) % 2 == 0){
		}else{
			ans = false;
			break;
		}
		tNow = tNext;
		xNow = xNext;
		yNow = yNext;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
