#include <iostream>
#include <cmath>
using namespace std;

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day(int m, int d){
	int ret = 0;
	for(int i = 0; i < m; i++){
		ret += days[i];
	}
	return ret + d;
}

int main(void)
{
	int Ma, Da;
	int Mb, Db;
	cin >> Ma >> Da;
	cin >> Mb >> Db;
	cout << day(Mb, Db) - day(Ma, Da) << endl;
	return 0;
}
