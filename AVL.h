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
 * Height of a node: MAX(height(left), height(right) + 1
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
 *
 *   Splay Trees
 *     - more memory efficient than AVL trees, they do not need to store balance information in the nodes
 *     - O(log n) on average for all operations
 *       - Single operations can take O(n) or O(1)
 *     - All operations involve a splay, (rotations) which keep the tree balanced.
 *       - Splaying enables the key to be accessed quicker than before
 *     - Splay trees are not kept perfectly balanced
 *
 *     3 Cases:
 *          1. If X is the left child of a right child || right child of a left child
 *              - Zig Zag
 *              - Rotate X with it's parent
 *              - Rotate X with what used to be grand parent
 *          2. If X is the left child of a left child || right child of a right child
 *              - Zig Zig
 *              - Rotate parent through the grand parent
 *              - Rotate X through the parent
 *
 *          Repeat Steps 1 and 2 until X is the root.
 *          3. If X is a child of the root
 *              - Zig
 *              - Rotate X through it's parent
 */

struct AVLNode {
    AVLNode* left;
    AVLNode* right;
    int value;
    int height;
    AVLNode(int v) : left(nullptr), right(nullptr), value(v), height(0) {}
};

class AVL {
    private:
        AVLNode* root;

        AVLNode* _insert(AVLNode*, int);
        AVLNode* _remove(AVLNode*, int);
        AVLNode* _destroy(AVLNode*);

        AVLNode* _balance(AVLNode*, int val);

        // returns height of the node
        int _height(AVLNode*);

        // rotations
        AVLNode* _leftRotation(AVLNode*);
        AVLNode* _rightRotation(AVLNode*);

        // traversal
        void _preOrderTraversal(AVLNode*);

        // helper functions
        int _getLeftMax(AVLNode*);
        int _getBalanceFactor(AVLNode*);
    public:
        AVL();
        ~AVL();

        void insert(int);
        void remove(int);

        void preOrderTraversal();
};


#endif //TREES_AVL_H
