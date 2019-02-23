#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)

int main(void)
{
	set<int> sta; // and
	set<int> sto; // or
	int Na, Nb;
	cin >> Na >> Nb;
	Rep(i, Na){
		int x;
		cin >> x;
		sto.insert(x);
	}
	Rep(i, Nb){
		int x;

		cin >> x;
		if(sto.find(x) != sto.end()){
			sta.insert(x);
		}else{
			sto.insert(x);
		}
	}
	printf("%.9f\n", (double)sta.size() / sto.size());
	return 0;
}
