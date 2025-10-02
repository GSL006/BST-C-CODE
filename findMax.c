#include <stdio.h>
#define MAX 100

int bst[MAX];
int size = 0;

int rightChild(int i) { return 2*i + 2; }

// Find maximum value
int findMax() {
    if (size == 0) return -1;
    int i = 0;
    while (rightChild(i) < size && bst[rightChild(i)] != -1)
        i = rightChild(i);
    return bst[i];
}
