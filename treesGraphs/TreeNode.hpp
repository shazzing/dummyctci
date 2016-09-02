//
//  TreeNode.hpp
//  ctci-bstSequence
//
//  Created by shashank hegde on 2/21/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <iostream>
#include <limits>
#include <vector>
using namespace std;
/* One node of a binary tree. The data element stored is a single
 * character.
 */
class TreeNode {
private: int size = 0;
    
public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int data;
    
    
    TreeNode(int d) {
        data = d;
        size = 1;
    }
    
     void setLeftChild(TreeNode* left) {
        this->left = left;
        if (left != nullptr) {
            left->parent = this;
        }
    }
    
     void setRightChild(TreeNode* right) {
        this->right = right;
        if (right != nullptr) {
            right->parent = this;
        }
    }
    
     void insertInOrder(int d) {
        if (d <= data) {
            if (left == nullptr) {
                setLeftChild(new TreeNode(d));
            } else {
                left->insertInOrder(d);
            }
        } else {
            if (right == nullptr) {
                setRightChild(new TreeNode(d));
            } else {
                right->insertInOrder(d);
            }
        }
        size++;
    }
    
     int Size() {
        return size;
    }
    
    bool isBST() {
        if (left != nullptr) {
            if (data < left->data || !left->isBST()) {
                return false;
            }
        }
        
        if (right != nullptr) {
            if (data >= right->data || !right->isBST()) {
                return false;
            }
        }
        
        return true;
    }
    
     int height() {
        int leftHeight = left != nullptr ? left->height() : 0;
        int rightHeight = right != nullptr ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }
    
    TreeNode* find(int d) {
        if (d == data) {
            return this;
        } else if (d <= data) {
            return left != nullptr ? left->find(d) : nullptr;
        } else if (d > data) {
            return right != nullptr ? right->find(d) : nullptr;
        }
        return nullptr;
    }
    
    static TreeNode* createMinimalBST(vector<int> arr, int start, int end){
        if (end < start) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* n = new TreeNode(arr[mid]);
        n->setLeftChild(createMinimalBST(arr, start, mid - 1));
        n->setRightChild(createMinimalBST(arr, mid + 1, end));
        return n;
    }
    
     static TreeNode* createMinimalBST(vector<int> arr) {
        return createMinimalBST(arr, 0, arr.size() - 1);
    }
    
  
};

#endif /* TreeNode_hpp */
