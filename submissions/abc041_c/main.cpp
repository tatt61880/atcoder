#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	pair<int, int> a[100000];
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int A;
		cin >> A;
		a[i - 1] = make_pair(-A, i);
	}
	sort(a, a+n);
	for(int i=1; i<=n; i++){
		cout << a[i - 1].second << endl;
	}
	return 0;
}
