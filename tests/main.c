#include "common.h"
int recur(int n)
{
  if (n == 1)
  {
    return 1;
  }
  int res = recur(n - 1);
  return n + res;
}
int main(int argc, char const *argv[])
{
  int *a;
  printf("结果是：%d\n", sizeof(a));
  return 0;
}
