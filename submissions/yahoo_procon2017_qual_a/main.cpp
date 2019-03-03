#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define PrintLn(X) cout << X << endl
#define Loop(n) for(int loop_ = n; loop_; --loop_)
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)
int main(void)
{
	char name[6];
	char yahoo[6] = "yahoo";
	cin >> name;
	sort(name, name + 5);
	sort(yahoo, yahoo + 5);
	if(strcmp(name, yahoo) == 0){
		PrintLn("YES");
	}else{
		PrintLn("NO");
	}
	return 0;
}
