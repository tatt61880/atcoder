#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define rep(i,n) for(int i = 0, i##_len=(n); i < i##_len; ++i)
typedef long long ll;

int main(){
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	cout << (s < t ? "Yes" : "No") << endl;
	return 0;
}
