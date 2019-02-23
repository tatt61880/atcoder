#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> x;
vector<int> y;

bool test(const vector<int> &v, int X)
{
	set<int> st;
	st.insert(v[0]);
	for(int i = 1; i < v.size(); i++){
		vector<int> tmp;
		for(auto& a: st){
			
tmp.push_back(a + v[i]);
			tmp.push_back(a - v[i]);
		}
		st.clear();
		for(auto& a: tmp){
			st.insert(a);
		}
	}
	return st.count(X);
}

int main(){
	string s;
	cin >> s;
	int X, Y;
	cin >> X >> Y;

	bool f = true;
	int num = 0;
	y.push_back(0);
	for(auto& c: s){
		if(c == 'F'){
			num++;
		}else{
			(f ? x : y).push_back(num);
			f = !f;
			num = 0;
		}
	}
	(f ? x : y).push_back(num);
	bool ans = (test(x, X) && test(y, Y));
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
