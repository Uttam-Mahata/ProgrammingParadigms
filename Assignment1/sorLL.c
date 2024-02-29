#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *merge(struct Node *left, struct Node *right) {
  struct Node *result = NULL;

  if (left == NULL)
    return right;
  if (right == NULL)
    return left;

  if (left->data <= right->data) {
    result = left;
    result->next = merge(left->next, right);
  } else {
    result = right;
    result->next = merge(left, right->next);
  }

  return result;
}

struct Node *mergeSort(struct Node *start) {
  if (start == NULL || start->next == NULL)
    return start;

  struct Node *slow = start;
  struct Node *fast = start->next;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  struct Node *left = start;
  struct Node *right = slow->next;
  slow->next = NULL;

  left = mergeSort(left);
  right = mergeSort(right);

  return merge(left, right);
}

void insertNode(struct Node **start, int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (*start == NULL) {
    *start = newNode;
  } else {
    struct Node *temp = *start;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void printList(struct Node *start) {
  while (start != NULL) {
    printf("%d ", start->data);
    start = start->next;
  }
  printf("\n");
}

void freeList(struct Node *start) {
  while (start != NULL) {
    struct Node *temp = start;
    start = start->next;
    free(temp);
  }
}

int main() {
  struct Node *start = NULL;

  insertNode(&start, 5);
  insertNode(&start, 3);
  insertNode(&start, 8);
  insertNode(&start, 1);
  insertNode(&start, 7);

  printf("Original Linked List: ");
  printList(start);

  start = mergeSort(start);

  printf("Sorted Linked List: ");
  printList(start);

  freeList(start);

  return 0;
}
