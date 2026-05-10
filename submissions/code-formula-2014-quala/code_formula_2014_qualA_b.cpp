#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(void)
{
 int a,b;
 cin>>a>>b;
 char x[10];
 rep(i,10) x[i]='x';
 int X;
 rep(i,a) cin>>X, x[X]='.';
 rep(i,b) cin>>X, x[X]='o';
 cout << x[7] << " " << x[8] << " " << x[9] << " " << x[0] << endl;
 cout << " " << x[4] << " " << x[5] << " " << x[6] << endl;
 cout << "  " << x[2] << " " << x[3] << endl;
 cout << "   " << x[1] << endl;
 return 0;
}
