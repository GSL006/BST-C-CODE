#include <stdbool.h>
#include <stdio.h>

#define MAX 100
#define EMPTY -1

int bst[MAX];
int size = 0;

void InsertArray(int data) {
  int index = 0;

  // Case 1: Tree is empty (insert at root)
  if (bst[0] == EMPTY) {
    bst[0] = data;
    return;
  }

  // Traverse the array to find the correct insertion spot
  while (index < MAX) {
    int next_index;

    // Determine direction based on BST property
    if (data <= bst[index]) {
      // Go Left: Left child index is 2 * i + 1
      next_index = 2 * index + 1;
    } else {
      // Go Right: Right child index is 2 * i + 2
      next_index = 2 * index + 2;
    }

    // Check if the next index is out of bounds
    if (next_index >= MAX) {
      printf(
          "Error: Cannot insert %d. Array is full along this path (MAX=%d).\n",
          data, MAX);
      return;
    }

    // Check if the insertion slot is empty
    if (bst[next_index] == EMPTY) {
      bst[next_index] = data;
      return;
    }

    // Move to the next level
    index = next_index;
  }
}
