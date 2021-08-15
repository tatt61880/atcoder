#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define rep(i,n) for(int i = 0, i##_len=(n); i < i##_len; ++i)
typedef long long ll;

int main(){
	int N;
	cin >> N;
	int ans = 0;
	map<int, int> mp;
	rep(i, N){
		int a;
		cin >> a;
		if(mp.find(a) == mp.end()){
			mp[a] = 1;
		}else{
			mp[a]++;
		}
	}
	for(auto& x: mp){
		int key = x.first;
		int val = x.second;
		if(key == val) continue;
		if(key < val){
			ans += val - key;
		}else{
			ans += val;
		}
	}
	cout << ans << endl;
	return 0;
}
