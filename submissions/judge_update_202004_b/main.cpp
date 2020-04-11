#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> r;
  vector<int> b;
  for(int i = 0; i < n; ++i){
    int x;
    char c;
    cin >> x >> c;
    (c == 'R' ? r : b).push_back(x);
  }
  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  for(int i = 0; i < r.size(); ++i) cout << r[i] << endl;
  for(int i = 0; i < b.size(); ++i) cout << b[i] << endl;
}
