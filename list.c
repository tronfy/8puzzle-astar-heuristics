#include "list.h"
#include <stdlib.h>

LNode ll_new(int data) {
  LNode head = malloc(sizeof(struct LNode));
  head->data = data;
  head->next = NULL;
  return head;
}

void ll_init(LNode *head) { *head = NULL; }

void ll_free(LNode head) {
  LNode current = head;
  while (current != NULL) {
    LNode next = current->next;
    free(current);
    current = next;
  }
}

void ll_push(LNode *head, int data) {
  LNode new = ll_new(data);

  if (*head == NULL) {
    *head = new;
    return;
  }

  LNode current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new;
}

int ll_exists(LNode head, int data) {
  LNode current = head;
  while (current != NULL) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}
