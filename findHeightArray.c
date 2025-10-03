#include <stdbool.h>
#include <stdio.h>

#define MAX 100
#define EMPTY -1

int bst[MAX];
int size = 0;

int max(int a, int b) { return (a > b) ? a : b; }

int FindHeightRecursive(int index) {
  // Base Case 1: Index is out of the array bounds
  if (index >= MAX) {
    return -1;
  }

  // Base Case 2: The slot is empty
  if (bst[index] == EMPTY) {
    return -1;
  }

  // Recursive Step:
  int leftHeight = FindHeightRecursive(2 * index + 1);
  int rightHeight = FindHeightRecursive(2 * index + 2);

  // Height is 1 (for the current node) + the maximum height of its subtrees
  return max(leftHeight, rightHeight) + 1;
}

int FindHeightArray() { return FindHeightRecursive(0); }
