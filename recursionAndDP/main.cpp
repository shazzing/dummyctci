//
//  main.cpp
//  recursionAndDP
//
//  Created by shashank hegde on 6/18/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "recursionDP1.h"
#include "stackExample.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int m_steps = steps(7);
    cout << " num of ways to cover 7 steps are : " << m_steps << endl;
    vector<vector<int>> grid(4, vector<int>(4, 0));
    grid[1][0] = 1, grid[0][2] = 1, grid[1][2] = 1, grid[2][3] = 1, grid[3][1] = 1;
    vector<pair<int, int>> rob_path = robotPath(grid);
    for(pair<int, int> pr:rob_path){
        cout << "{" << pr.first << "," << pr.second << "}, ";
    }
    cout << endl;
    
    vector<string> permutation = getPermutation("aabc");
    for(string& str: permutation){
        cout << str << ", ";
    }
    cout << endl;
    vector<string> validParen = matchParens(3);
    for(string& str: validParen){
        cout << str << ", ";
    }
    
    stack<int> mainstk;
    mainstk.push(3);
    mainstk.push(2);
    mainstk.push(7);
    mainstk.push(1);
    mainstk.push(9);
    mainstk.push(10);
    mainstk.push(4);
    mainstk.push(13);
    mainstk.push(78);
    mainstk.push(0);
    mainstk.push(67);
    mainstk.push(34);
    sortStk(mainstk);
    while(!mainstk.empty()){
        cout << mainstk.top() << endl;
        mainstk.pop();
    }
    
    return 0;
}
