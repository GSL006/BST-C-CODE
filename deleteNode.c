#include <stdio.h>
#define MAX 100

int bst[MAX];
int size = 0; // number of elements

int leftChild(int i) { return 2*i + 1; }
int rightChild(int i) { return 2*i + 2; }

// Delete node function
void deleteNode(int val) {
    if (size == 0) return;

    int i = 0;
    while (i < size && bst[i] != val) {
        if (val < bst[i])
            i = leftChild(i);
        else
            i = rightChild(i);
    }

    if (i >= size || bst[i] != val) return;

    int l = leftChild(i), r = rightChild(i);

    // Case 1: Leaf
    if ((l >= size || bst[l] == -1) && (r >= size || bst[r] == -1)) {
        bst[i] = -1;
        return;
    }

    // Case 2 & 3: Node with one or two children
    if (r < size && bst[r] != -1) {
        int succ = r;
        while (leftChild(succ) < size && bst[leftChild(succ)] != -1)
            succ = leftChild(succ);
        bst[i] = bst[succ];
        deleteNode(bst[succ]);
    } else if (l < size && bst[l] != -1) {
        bst[i] = bst[l];
        deleteNode(bst[l]);
    }
}
