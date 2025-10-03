#include <stdbool.h>
#include <stdio.h>

bool SearchArray(int data) {
  int index = 0;

#define MAX 100
#define EMPTY -1

  int bst[MAX];
  int size = 0;

  // Traverse until the index goes out of bounds (up to MAX)
  while (index < MAX) {
    // If the current slot is empty, the data is not in this subtree
    if (bst[index] == EMPTY) {
      return false;
    }

    // Case 1: Found the element
    if (bst[index] == data) {
      return true;
    }
    // Case 2: Target is smaller, move to the left child
    else if (data < bst[index]) {
      index = 2 * index + 1;
    }
    // Case 3: Target is larger, move to the right child
    else {
      index = 2 * index + 2;
    }
  }

  // Index went out of bounds without finding the data
  return false;
}
