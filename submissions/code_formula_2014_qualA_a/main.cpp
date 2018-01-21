#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	b=cbrt(a);
	if (b*b*b==a) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
