#include "item.h"

typedef struct list *List;

// Create a new list
List newList();
// return 1 i the list is empty and 0 if the list isn't empty
int isEmpty(List);
// Add an element in head position of the list
void addHead(List, Item);
// remove ad return the element in the head
Item removeHead(List);
// return the valure of the head node
Item getHead(List);
// return the size of the list
int sizeList(List);
// print the list
void printList(List);
// Search an item in the list and load his position in an variable
Item searchListItem(List, Item, int *);
// remove ad return the element
Item removeListItem(List, Item);
// remove ad return the element by position
Item removeListPos(List, int);
int addListPos(List, Item, int);
int addListTail(List, Item);
void reverseList(List);
List cloneList(List);
List cloneListItem(List);