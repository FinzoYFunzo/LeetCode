// Last Submission
// 0ms - Beats 100.00%

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;
 

struct ListNode* addTwoNumbersRecursive(struct ListNode* l1, struct ListNode* l2, int carry) {
  struct ListNode* node = malloc(sizeof(struct ListNode));

  if (!l1 && !l2){
    if (carry) {
      node->val = carry;
      node->next = NULL;
      return node;
    }
    return NULL;
  }
  else if (!l1) {
    int sum = l2->val + carry;

    node -> val = sum % 10;
    carry = sum / 10;

    node -> next = addTwoNumbersRecursive(l1, l2 -> next, carry);
  }
  else if (!l2) {
    int sum = l1->val + carry;
    
    node -> val = sum % 10;
    carry = sum / 10;

    node -> next = addTwoNumbersRecursive(l1 -> next, l2, carry);
  }
  else {
    int sum = l1->val + l2->val + carry;

    node -> val = sum % 10;
    carry = sum / 10;

    node -> next = addTwoNumbersRecursive(l1->next, l2->next, carry);
  }

  return node;
}

// Esto es lo que ocupa CodeForce
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addTwoNumbersRecursive(l1, l2, 0);
}

// Testing
int main() {
  int l1_nums[] = {2,4,3};
  int l2_nums[] = {5,6,4};
  struct ListNode* l1 = calloc(1, sizeof(ListNode));
  struct ListNode* l2 = calloc(1, sizeof(ListNode));

  struct ListNode* l1_p = l1;
  struct ListNode* l2_p = l2;
  
  for (int i = 0; i < 3; i++ ){
    l1_p->val = l1_nums[i];
    l2_p->val = l2_nums[i];

    l1_p->next = calloc(1, sizeof(ListNode));
    l2_p->next = calloc(1, sizeof(ListNode));

    l1_p = l1_p->next;
    l2_p = l2_p->next;
  }

  struct ListNode* node = addTwoNumbersRecursive(l1, l2, 0);
  
  for (int i = 0; i < 3; i++){
    printf("%d", node->val);
    ListNode* prev = node;
    node = node->next;
    free(prev);
}