#include "item.h"
#include <stdio.h>
#include <stdlib.h>

Item inputItem() {
  int *p = malloc(sizeof(int));
  if (!scanf("%d", p))
    exit(EXIT_FAILURE);

  return p;
}

void outputItem(Item a) {
  int *p = a;
  printf("%d ", *p);
}

int cmpItem(Item a, Item b) {
  int *p1 = a;
  int *p2 = b;

  return (*p1 - *p2);
}