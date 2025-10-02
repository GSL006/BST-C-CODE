#include <stdio.h>
#define MAX 100

int bst[MAX];
int size = 0;

// Count nodes in BST
int countNodes() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (bst[i] != -1) count++;
    }
    return count;
}
