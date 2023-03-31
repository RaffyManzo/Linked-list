#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  List list = newList();
  int i;
  int search;
  Item stampa;
  Item removedItem;

  printf("\nInserisci gli elementi: \n");

  for (i = 0; i < 5; i++) {
    addHead(list, inputItem());
  }

  printList(list);
  printf("\nInserisci una posizione da eliminare: ");

  if (!scanf("%d", &search))
    exit(EXIT_FAILURE);
  stampa = removeListPos(list, search);

  if (stampa == NULL)
    printf("\n\nErrore, item non trovato\n");
  else {
    printf("\nItem ");
    outputItem(stampa);
    printf(" Eliminato\n");
  }

  printList(list);
  printf("\n");
  return 0;
}