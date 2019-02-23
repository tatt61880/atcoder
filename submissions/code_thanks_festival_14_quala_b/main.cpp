#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(void)
{
	int n;
	cin >> n;
	int a[3];
	rep(i, 3) cin >> a[i];
	if(a[0] &lt
; a[1]) swap(a[0], a[1]);
	if(a[0] < a[2]) swap(a[0], a[2]);
	if(a[1] < a[2]) swap(a[1], a[2]);
	int sum = 0;
	int i = 0;
	while(1){
		sum += a[i++ % 3];
		if(sum >= n) break;
	}
	cout << i << endl;
	return 0;
}
