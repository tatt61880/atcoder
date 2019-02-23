#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int N, M;
int a[50];
int b[50];
vector<int> vs[100];

int main(void)
{
	cin >> N >> M;

	Rep(i, M){
		cin >> a[i
] >> b[i];
		a[i]--;
		b[i]--;
		vs[a[i]].push_back(b[i]);
		vs[b[i]].push_back(a[i]);
	}

	int ans = 0;
	Rep(i, M){
		int A = a[i];
		int B = b[i];
		int nums[50] = {0};

		queue<int> q;
		nums[A] = 1;
		for(auto &x: vs[A]){
			if(x != B){
				q.push(x);
				nums[x] = 2;
			}
		}
		while(!q.empty()){
			int X = q.front();
			int num = nums[X];
			q.pop();
			for(auto &x: vs[X]){
				if(x == B) goto F;
				if(nums[x] == 0){
					q.push(x);
					nums[x] = num + 1;
				}
			}
		}
		ans++;
F:;
	}

	PrintLn(ans);
	return 0;
}
