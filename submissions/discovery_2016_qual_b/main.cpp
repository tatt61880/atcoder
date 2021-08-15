#include <cstdio>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define INTEREST_MAX 100000

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> interest[INTEREST_MAX];
	rep(i, n){
		int a;
		scanf("%d", &a);
		a--;
		interest[a].push_back(i);
	}
	int ans = 0;
	int last = INTEREST_MAX + 1;
	rep(i, INTEREST_MAX){
		int end = -1;
		int temp = -1;
		for(auto& x: interest[i]){
			if(x < last) end = x;
			temp = x;
		}
		if(end == -1){
			if(temp != -1) last = temp;
		}else{
			ans++;
			last = end;
		}
	}
	if(last == 0){
		ans--;
	}
	printf("%d\n", ans);
	return 0;
}
