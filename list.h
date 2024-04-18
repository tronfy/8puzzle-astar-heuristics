#ifndef LIST_H
#define LIST_H

struct LNode {
  int data;
  struct LNode *next;
};
typedef struct LNode *LNode;

void ll_init(LNode *head);
LNode ll_new(int data);
void ll_free(LNode head);
void ll_push(LNode *head, int data);
int ll_exists(LNode head, int data);

#endif
