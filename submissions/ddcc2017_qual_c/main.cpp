#include <iostream>
#include <algorithm>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int L[100000];
int main(void)
{
	int N, C;
	cin >> N >> C;
	Rep(i, N){
		cin >> L[i];
	}
	sort(L, L + N);

	int l = 0, r = N - 1;
	int ans = 0;
	while(1){
		if(l < r){
			if(L[l] + L[r] + 1 <= C){
				ans++;
				l++;
				r--;
			}else{
				ans++;
				r--;
			}
		}else{
			if(l == r){
				ans++;
			}
			break;
		}
	}
	PrintLn(ans);
	return 0;
}
