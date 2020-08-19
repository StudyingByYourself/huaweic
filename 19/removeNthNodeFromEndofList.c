#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getLinkLength(struct ListNode *head)
{
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (head == NULL) {
        return NULL;
    }
    int length = getLinkLength(head) - n;
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *cur = dummyHead;
    while (length > 0) {
        cur = cur->next;
        length--;
    }
    cur->next = cur->next->next;
    return dummyHead->next;
}