#include <cstdio>
int main(void)
{
  int x;
  scanf("%d", &x);
  printf("A%cC\n", x < 1200 ? 'B' : 'R');
  return 0;
}