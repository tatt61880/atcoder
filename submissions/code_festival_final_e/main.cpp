#include <iostream>
#include <vector>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, m, n) for(int i = m; i < (int)(n); ++i)

int main(void)
{
	int N;
	cin >> N;
	vector<int> R;
	Rep(i, N){
	
	int x;
		cin >> x;
		if(i == 0 || x != R[R.size() - 1]){
			R.push_back(x);
		}
	}
	if(R.size() < 3){
		PrintLn(0);
		return 0;
	}
	bool upFlag = (R[1] > R[0]);
	int ans = 2;
	For(i, 1, R.size()){
		if(upFlag){
			if(R[i] < R[i - 1]){
				ans++;
				upFlag = false;
			}
		}else{
			if(R[i] > R[i - 1]){
				ans++;
				upFlag = true;
			}
		}
	}
	if(ans < 3) ans = 0;
	PrintLn(ans);
	return 0;
}
