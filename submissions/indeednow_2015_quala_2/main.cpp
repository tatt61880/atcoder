#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(void)
{
	char indeednow[]="indeednow";
	sort(indeednow, indeednow+strlen(indeednow));
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		char buf[101];
		cin >> buf;
		sort(buf, buf+strlen(buf));
		if(strcmp(buf, indeednow) == 0){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
