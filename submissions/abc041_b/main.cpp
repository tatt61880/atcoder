#include<iostream>
using namespace std;
int main(){
 long long a,b,c;
 cin>>a>>b>>c;
 a*= b;
 a%=1000000007;
 a*= c;
 a%=1000000007;
 cout<<a<<endl;
 return 0;
}