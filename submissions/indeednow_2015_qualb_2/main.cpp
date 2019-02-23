#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b;
	cin >> a >> b;
	if(a.size() != b.size()){
		cout << -1 << endl;
		return 0;
	}
	for(int i=0; i<a.size(); i++){
		if(a == b){
			cout << i << endl;
			return 0;
		}
		a = a[a.size()-1] + a.substr(0, a.size()-1);
	}
	cout << -1 
<< endl;
	return 0;
}
