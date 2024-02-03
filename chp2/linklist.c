#include "common.h"

/* insert pnode node behind the snode */
/* snode-->pnode */
void insert(ListNode *snode, ListNode *pnode)
{
  ListNode *node = snode->next;
  pnode->next = node;
  snode->next = pnode;
}

/* delete the node after the n0 */
void removeItem(ListNode *n0)
{
  if (n0->next == NULL)
  {
    return;
  }
  /* n0-->n1-->n2 */
  ListNode *n1 = n0->next;
  ListNode *n2 = n1->next;
  n0->next = n2;
  free(n1);
}

/* access the node in the index */
ListNode *access(ListNode *list, int index)
{
  for (int i = 0; i < index; i++)
  {
    if (list == NULL)
      return NULL;
    list = list->next;
  }
  return list;
}

/* search the node that value==target */
int find(ListNode *list, int target)
{
  int index = 0;
  while (list != NULL)
  {
    if (list->value == target)
      return index;
    index++;
    list = list->next;
  }
  return -1;
}

int main()
{
  /* init the list node */
  ListNode *n0 = newListNode(3);
  ListNode *n1 = newListNode(5);
  ListNode *n2 = newListNode(1);
  ListNode *n3 = newListNode(9);
  ListNode *n4 = newListNode(8);
  /* build the linklist */
  /* n0-->n1-->n2-->n3-->n4 */
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  printf("the linklist is:\r\n");
  printLinkedList(n0);

  /* insert the node */
  insert(n0, newListNode(2));
  printf("the linklist after insert is:\r\n");
  printLinkedList(n0);

  /* delete the node after the n3 */
  removeItem(n3);
  printf("the linklist after delete is:\r\n");
  printLinkedList(n0);

  /* access the node in the index 3 */
  ListNode *node = access(n0, 3);
  printf("access the node in the index 3:\r\n");
  printf("the value is %d\r\n", node->value);

  /* find the value's index */
  int index = find(n0, 2);
  printf("find the value's index:\r\n");
  printf("the index is %d\r\n", index);

  /* free the memory */
  freeList(n0);
}