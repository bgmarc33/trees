//
// Created by Bryan Giordano on 4/21/19.
//

#ifndef TREES_AVL_H
#define TREES_AVL_H

/*
 * AVL Trees are self balancing binary search trees
 * determined by a balance factor.
 *
 * BF = height(L) - height(R)
 * if BF == 1, 0, -1, then the tree is balanced
 *
 * Rotations:
 *   Left and Right rotations are performed to
 *   preserve the balance
 *
 *   If the left sub tree is greater than the right:
 *   if the left sub tree is equal to 1, perform right rotation
 *   if the left sub tree is equal to -1, perform left, then right rotation
 *
 *   If the right sub tree is greater than the left:
 *   if the right sub tree is equal to -1, perform left rotation
 *   if the right sub tree is equal to 1, perform right, then left rotation
 *
 */

struct AVLNode {
    AVLNode* left;
    AVLNode* right;
    int value;
    AVLNode(int v) : left(nullptr), right(nullptr), value(v) {}
};

class AVL {
    private:
        AVLNode* root;

    public:
        AVL():root(nullptr){}

};


#endif //TREES_AVL_H
