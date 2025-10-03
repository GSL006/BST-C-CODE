#include <stdbool.h>
#include <stdio.h>

#define MAX 100
#define EMPTY -1

int bst[MAX];
int size = 0;

int FindMinArray() {
  // Case: Empty tree
  if (bst[0] == EMPTY) {
    return EMPTY;
  }

  int index = 0;

  // Keep traversing left (2*i + 1) until the next left child is empty or out of
  // bounds
  while (index < MAX) {
    int left_index = 2 * index + 1;

    // If the left child slot is out of bounds OR empty, the current node is the
    // minimum.
    if (left_index >= MAX || bst[left_index] == EMPTY) {
      return bst[index];
    }

    index = left_index;
  }

  return EMPTY;
}
