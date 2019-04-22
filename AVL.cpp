//
// Created by Bryan Giordano on 4/21/19.
//
//

#include <algorithm>
#include <iostream>
#include "AVL.h"

AVL::AVL()
:
root(nullptr){}

AVL::~AVL() {
    this->root = this->_destroy(this->root);
}

AVLNode* AVL::_destroy(AVLNode* node) {
    if (!node) {
        return node;
    }

    node->left = this->_destroy(node->left);
    node->right = this->_destroy(node->right);

    delete node;
    node = nullptr;
    return node;
}

int AVL::_height(AVLNode* node) {
    if (!node) {
        return -1;
    }

    return node->height;
}

AVLNode* AVL::_balance(AVLNode* node, int val) {
    // get the balance factor
    int balanceFactor = this->_getBalanceFactor(node);

    // Left Left Case
    if (balanceFactor > 1 && val < node->left->value) {
        return _rightRotation(node);
    }

    // Right Right Case
    if (balanceFactor < -1 && val > node->right->value) {
        return _leftRotation(node);
    }

    // Left Right Case
    if (balanceFactor > 1 && val > node->left->value) {
        node->left = _leftRotation(node->left);
        return _rightRotation(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && val < node->right->value) {
        node->right = _rightRotation(node->right);
        return _leftRotation(node);
    }

    return node;
}

int AVL::_getBalanceFactor(AVLNode* node) {
    if (!node) {
        return 0;
    }

    return this->_height(node->left) - this->_height(node->right);
}

void AVL::insert(int val) {
    this->root = this->_insert(this->root, val);
}

AVLNode* AVL::_insert(AVLNode* node, int val) {
    if (!node) {
        node = new AVLNode(val);
    } else if (node->value > val) {
        node->left = this->_insert(node->left, val);
    } else if (node->value < val) {
        node->right = this->_insert(node->right, val);
    }

    // update the height of the node
    node->height = 1 + std::max(this->_height(node->left), this->_height(node->right));

    // balance
    node = this->_balance(node, val);
    return node;
}

AVLNode* AVL::_leftRotation(AVLNode* node) {
    AVLNode* n = node->right;
    node->right = n->left;
    n->left = node;

    node->height = std::max(this->_height(node->left), this->_height(node->right)) + 1;
    n->height = std::max(this->_height(n->left), this->_height(n->right)) + 1;
    return n;
}

AVLNode* AVL::_rightRotation(AVLNode* node) {
    AVLNode* n = node->left;
    node->left = n->right;
    n->right = node;

    node->height = std::max(this->_height(node->left), this->_height(node->right)) + 1;
    n->height = std::max(this->_height(n->left), this->_height(n->right)) + 1;
    return n;
}

void AVL::remove(int val) {
    this->root = this->_remove(this->root, val);
}

AVLNode* AVL::_remove(AVLNode* node, int val) {
    if (node) {
        if (node->value > val) {
            node->left = this->_remove(node->left, val);
        } else if (node->value < val) {
            node->right = this->_remove(node->right, val);
        } else {
            // found node
            if (node->left && node->right) {
                node->value = _getLeftMax(node->left);
                node->left = this->_remove(node->left, node->value);
            } else if (node->left || node->right) {
                AVLNode* temp = node;
                if (node->left) {
                    node = node->left;
                } else {
                    node = node->right;
                }

                delete temp;
                temp = nullptr;
            } else {
                // 0 children
                delete node;
                node = nullptr;
            }
        }

        // balance
        this->_balance(node, val);
    }

    return node;
}

int AVL::_getLeftMax(AVLNode* node) {
    while (node->right) {
        node = node->right;
    }

    return node->value;
}

void AVL::preOrderTraversal() {
    this->_preOrderTraversal(this->root);
}

void AVL::_preOrderTraversal(AVLNode* node) {
    if (!node) {
        return;
    }

    std::cout << node->value << std::endl;
    this->_preOrderTraversal(node->left);
    this->_preOrderTraversal(node->right);
}