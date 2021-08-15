#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	int N, K;
	cin >> N >> K;
	priority_queue<int> pq;
	map<int, int> mp;

	Rep(i, N){
		int x;
		cin >> x;
		pq.push(x);
		mp[x] = i + 1;
		if(i >= K - 1){
			if(pq.size() > K){
				pq.pop();
			}
			PrintLn(mp[pq.top()]);
		}
	}
	return 0;
}
