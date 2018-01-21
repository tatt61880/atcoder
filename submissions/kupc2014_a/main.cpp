#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{
	int a[3], b[3];
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
	sort(a, a+3);
	sort(b, b+3);
	int sum = 0;
	for(int i=0; i<3; i++) sum += abs(a[i] - b[i]);
	cout << sum << endl;
	return 0;
}
