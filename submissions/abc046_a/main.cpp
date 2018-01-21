
#include<iostream>
using namespace std;
int main(){
 int a,b,c;
 cin>>a>>b>>c;
 cout<<(3-(a==b)-(b==c)-(c==a)+(a==b&&b==c))<<endl;
 return 0;
}