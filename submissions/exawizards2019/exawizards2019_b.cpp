#include <iostream>
using namespace std;

int main()
{
  int N;
  string s;
  cin >> N >> s;
  int count = 0;
  for (auto &c: s)
  {
    if (c == 'R') count++;
  }
  printf("%s\n", count * 2 > N ? "Yes" : "No");
  return 0;
}