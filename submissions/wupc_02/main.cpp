#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += "...";
	int ans = 0;
	for(int i=0; i<n;){
		if(s[i+3] == '.'){ i += 3; continue; }
		if(s[i+2] == '.'){ i += 2; continue; }
		if(s[i+1] == '.'){ i += 1; continue; }
		i += 3;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
