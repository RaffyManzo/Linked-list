#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Item value;
  struct node *next;
};

struct list {
  int size;
  struct node *head;
} list;

List newList() {
  List list = malloc(sizeof(struct list));

  if (!list)
    exit(EXIT_FAILURE);

  list->head = NULL;
  list->size = 0;

  return list;
}

int isEmpty(List list) { return !(list->size != 0); }

void addHead(List list, Item item) {
  struct node *newHead = malloc(sizeof(struct node));
  if (!newHead)
    exit(EXIT_FAILURE);

  newHead->value = item;
  newHead->next = list->head;

  list->head = newHead;
  list->size += 1;
}

Item removeHead(List list) {
  if (isEmpty(list))
    return NULL;

  Item item = list->head->value;
  // I must free allocated memory for head node, so with a temp pointer save the
  // address of the head node
  struct node *temp = list->head;

  list->head = list->head->next;
  list->size -= 1;

  free(temp);

  return item;
}

Item getHead(List list) { return list->head->value; }

int sizeList(List list) { return list->size; }

void printList(List list) {
  struct node *current = list->head;

  while (current != NULL) {

    outputItem(current->value);

    current = current->next;
  }
}

Item searchListItem(List list, Item item, int *position) {
  struct node *current = list->head;

  for (*position = 0; current != NULL; (*position)++) {
    if (cmpItem(current->value, item) == 0)
      return current->value;

    current = current->next;
  }

  *position = -1;

  return NULL;
}

Item removeListItem(List list, Item item) {
  if (isEmpty(list))
    return NULL;

  // Use two pointer to struct node, one used to iterate the list, and one to
  // load the previusly node
  struct node *current = list->head, *prev = NULL;
  Item removedItem;

  while (current != NULL) {
    if (cmpItem(current->value, item) == 0) {
      if (prev == NULL) {
        return removeHead(list);
      } else {
        removedItem = current->value;
        prev->next = current->next;

        list->size--;
        free(current);

        return removedItem;
      }
    }

    prev = current;
    current = current->next;
  }

  return NULL;
}

Item removeListPos(List list, int pos) {
  struct node *prev, *current;
  Item val;
  int i;

  if (isEmpty(list) || pos < 0 || pos >= list->size)
    return NULL;
  for (i = 0, current = list->head; current != NULL;
       prev = current, current = current->next, i++) {
    if (i == pos) {
      if (current == list->head)
        return removeHead(list);
      else {
        prev->next = current->next;
        val = current->value;
        (list->size)--;
        free(current);
        return val;
      }
    }
  }
  return NULL;
}