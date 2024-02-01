#include <stdio.h>
#include "common.h"
int main(int argc, char const *argv[])
{
  int array[MAX_SIZE];
  for (int i = 0; i < MAX_SIZE; i++)
  {
    array[i] = 0;
    printf("array[%d] = %d\n", i, array[i]);
  }

  return 0;
}
