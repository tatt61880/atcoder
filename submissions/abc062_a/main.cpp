#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define PrintLn(X) cout << X << endl
int main(void)
{
	int x, y;
	cin >> x >> y;
	int arr[] = {1, -2, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
	cout << ((arr[x - 1] == arr[y - 1]) ? "Yes" : "No") << endl;
	return 0;
}
