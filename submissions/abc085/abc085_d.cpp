#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define printLn(X) cout << X << endl
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int a[100000];
int b[100000];
int main(){
	int N, H;
	cin >> N >> H;
	rep(i, N){
		cin >> a[i] >> b[i];
	}
	sort(a, a + N);
	sort(b, b + N);
	reverse(b, b + N);
	int maxA = a[N - 1];
	int ans = 0;
	rep(i, N){
		if(b[i] <= maxA){
			break;
		}
		ans++;
		H -= b[i];
		if(H <= 0){
			printLn(ans);
			return 0;
		}
	}
	ans += (H + maxA - 1) / maxA;
	printLn(ans);
	return 0;
}
