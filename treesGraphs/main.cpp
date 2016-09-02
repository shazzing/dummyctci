//
//  main.cpp
//  ctci-bstSequence
//
//  Created by shashank hegde on 2/21/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "TreeNode.hpp"
#include <List>

 void weaveLists(list<int> first, list<int> second, vector<list<int>>& results, list<int> prefix) {
    /* One list is empty. Add the remainder to [a cloned] prefix and
     * store result. */
    if (first.size() == 0 || second.size() == 0) {
        list<int> result(prefix.begin(), prefix.end());
        result.emplace_back(first.begin(), first.end());
        result.emplace_back(second.begin(), second.end());
        results.emplace_back(result);
        return;
    }
    
    /* Recurse with head of first added to the prefix. Removing the
     * head will damage first, so we’ll need to put it back where we
     * found it afterwards. */
    int headFirst = first.front();
    prefix.push_back(headFirst);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    first.push_front(headFirst);
    
    /* Do the same thing with second, damaging and then restoring
     * the list.*/
    int headSecond = second.front();
    prefix.push_back(headSecond);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    second.push_front(headSecond);
}

 vector<list<int>> allSequences(TreeNode* node) {
     vector<list<int>> result;
    
    if (node == nullptr) {
        result.push_back(list<int>());
        return result;
    }
    
    list<int> prefix;
    prefix.push_back(node->data);
    
    /* Recurse on left and right subtrees. */
    vector<list<int>> leftSeq = allSequences(node->left);
    vector<list<int>> rightSeq = allSequences(node->right);
    
    /* Weave together each list from the left and right sides. */
    for (list<int> left : leftSeq) {
        for (list<int> right : rightSeq) {
            vector<list<int>> weaved;
            weaveLists(left, right, weaved, prefix);
            result.emplace_back(weaved.begin(), weaved.end());
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node = new TreeNode(100);
    vector<int> array = {100, 50, 20, 75, 150, 120, 170};
    for (int a : array) {
        node->insertInOrder(a);
    }
    vector<list<int>> allSeq = allSequences(node);
    for(list<int> l: allSeq){
        for(int item: l){
            cout << item << " " ;
        }
        cout << endl;
    }
    /*for (list<int> list : allSeq) {
        cout << list;
    }
    System.out.println(allSeq.size());
}
     */
    return 0;
}
