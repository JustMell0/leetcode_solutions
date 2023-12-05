#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TListNode {
  struct ListNode *first;
};

int main(){
  struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));

  l1->val = 2;
  l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l1->next->val = 4;
  l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l1->next->next->val = 3;
  l1->next->next->next = NULL;

  l2->val = 5;
  l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l2->next->val = 6;
  l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
  l2->next->next->val = 4;
  l2->next->next->next = NULL;

  addTwoNumbers(l1, l2);

  return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *tmp_l1 = l1->next;
  struct ListNode *tmp_l2 = l2->next;
  struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode));
  int carry = 0;
  int iteration = 0;
  while (tmp_l1 != NULL || tmp_l2 != NULL){
    ans->val = tmp_l1->val + tmp_l2->val + carry;
    tmp_l1 = tmp_l1->next;
    tmp_l2 = tmp_l2->next;
  }
  printf("ans->val: %d\n", ans->val);
  return l1;
}
