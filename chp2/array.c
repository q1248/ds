#include <stdio.h>
#include "common.h"

int randomAccess(ElementType *nums, int size)
{
  int randomIndex = rand() % size;
  ElementType randomNum = nums[randomIndex];
  return randomNum;
}

void insert(ElementType *nums, int size, int index, ElementType num)
{
  for (int i = size - 1; i > index; i--)
  {
    nums[i] = nums[i - 1];
  }
  nums[index] = num;
}
void deleteItem(ElementType *nums, int size, int index)
{
  for (int i = index; i < size - 1; i++)
  {
    nums[i] = nums[i + 1];
  }
}

void traverse(ElementType *nums, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

int find(int *nums, int size, ElementType target)
{
  for (int i = 0; i < size; i++)
  {
    if (target == nums[i])
    {
      return i;
    }
  }
  return -1;
}

int *extent(int *nums, int size, int enlarge)
{
  int *res = (int *)malloc(sizeof(ElementType) * (size + enlarge));
  for (int i = 0; i < size; i++)
  {
    res[i] = nums[i];
  }

  for (int i = size; i < (size + enlarge); i++)
  {
    res[i] = 0;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  /*  init an array */
  int size = 5;
  ElementType arr[] = {1, 4, 3, 4, 6};
  printf("array nums= ");
  printArray(arr, size);

  /* random access */
  ElementType randomNum = randomAccess(arr, size);
  printf("get random value: %d\n", randomNum);

  /* length extent */
  int enlarge = 3;
  ElementType *res = extent(arr, size, enlarge);
  printArray(res, size + enlarge);

  /* delete an element */
  deleteItem(arr, size, 2);
  printf("delete index 2 element,get array = ");
  size--;
  printArray(arr, size);

  /* traverse array*/
  traverse(arr, size);

  /* find element */
  int index = find(arr, size, 4);
  printf("find element 3 in arr,get index = %d \n", index);

  /* free res array's  memory */
  free(res);

  return 0;
}
