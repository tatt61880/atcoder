#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (n); ++i)
int main(void)
{
	int N, Q;
	cin >> N >> Q;
	vector<int> vy;
	vector<string> vn;
	vy.push_back(0);
	vn.push_back("kogakubu10gokan");
	Rep(i, N){
		int year;
		string name;
		cin >> year;
		cin >> name;
		vy.push_back(year);
		vn.push_back(name);
	}
	vy.push_back(100);
	while(1){
		static int i = 0;
		if(vy[i] > Q){
			PrintLn(vn[i - 1]);
			break;
		}
		i++;
	}
	return 0;
}
