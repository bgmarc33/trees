#include <iostream>
#include "AVL.h"

int main() {
    AVL avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    avl.insert(6);
    avl.insert(7);

    avl.preOrderTraversal();
    return 0;
}