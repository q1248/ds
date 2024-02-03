#pragma once

typedef struct ListNode
{
    int value;
    struct ListNode *next;

} ListNode;

/* generate a List with a value */
ListNode *newListNode(int value)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

/* generate a List with an array */
ListNode *arrToLinkedList(const int *arr, size_t size)
{
    if (size <= 0)
    {
        return NULL;
    }
    ListNode *res = newListNode(arr[0]);
    ListNode *node = res;
    for (int i = 1; i < size; i++)
    {
        node->next = newListNode(arr[i]);
        node = node->next;
    }
    node->next = NULL;
    return res;
}

/* get a list node with specific value from a List */
ListNode *getListNode(ListNode *head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
        {
            return head;
        }
        head = head->next;
    }
}

void freeList(ListNode *head)
{
    ListNode *node;
    while (head != NULL)
    {
        node = head->next;
        free(head);
        head = node;
    }
}