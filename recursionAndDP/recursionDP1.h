//
//  recursionDP1.h
//  recursionAndDP
//
//  Created by shashank hegde on 6/18/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef recursionDP1_h
#define recursionDP1_h
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;


int stepsHelper(int numStepLeft, vector<int>& numWays){
    if(numStepLeft < 1) return 0;
    if(numWays[numStepLeft] == -1){
        numWays[numStepLeft] = stepsHelper(numStepLeft-1, numWays);
        numWays[numStepLeft] += stepsHelper(numStepLeft-2, numWays);
        numWays[numStepLeft] += stepsHelper(numStepLeft-3, numWays);
    }
    return numWays[numStepLeft];
}

// Tripe steps
int steps(int numSteps){
    vector<int> numWays(numSteps+1, -1);
    numWays[0] = 0;
    numWays[1] = 1;
    numWays[2] = 2; // 1+1, 2
    numWays[3] = 3; // 3, 2+1, 1 + 1 + 1
    return stepsHelper(numSteps, numWays);
}


bool robotPathHelper(const vector<vector<int>>& grid, const pair<int, int>& start, const pair<int, int>& dest, vector<pair<int, int>>& currPath ){
    if(start == dest){
        return true;
    }
    
    pair<int, int> nextStart(start.first, start.second+1);
    currPath.emplace_back(nextStart);
    
    // check if we can go right
    if(nextStart.second < grid[0].size() && !grid[nextStart.first][nextStart.second] && robotPathHelper(grid, nextStart, dest, currPath) ){
        return true;
    }
    else{
        currPath.pop_back();
    }
    nextStart = {start.first + 1, start.second}; // moving down
    currPath.emplace_back(nextStart);
    if(nextStart.first < grid.size() && !grid[nextStart.first][nextStart.second] && robotPathHelper(grid, nextStart, dest, currPath) ){
        return true;
    }
    else{
        currPath.pop_back();
        return false;
    }
    
}




// robot in a grid
// we assume the off-Limit cells have 1, 0 represent a cell that can be traversed
vector<pair<int, int>> robotPath(const vector<vector<int>>& grid ){
    vector<pair<int, int>> currPath;
    robotPathHelper(grid, make_pair(0,0), make_pair(grid.size()-1, grid[0].size()-1), currPath);
    return currPath;
}


int magicIndexHelper(const vector<int>& arr, size_t start, size_t end){
    if(start >= end){
        return -1; // simple comment to show commit.
    }
    
    size_t mid = start + (end-start)/2;
    if(arr[mid] == mid){
        return mid;
    }
    if(arr[mid] > mid){
        return magicIndexHelper(arr, mid + 1, end);
    }
    return magicIndexHelper(arr, start, mid-1);
}

int magicIndex(const vector<int>& arr){
    if(arr.empty())
        return -1;
    return magicIndexHelper(arr, 0, arr.size()-1);
}


// sort the string and then swap to create lexicographical bigger strings
vector<string> getPermutation(string str){
    vector<string> result;
    if(str.empty()){
        return result;
    }
    sort(str.begin(),str.end());
    do{
        result.emplace_back(str);
        
    }while(next_permutation(str.begin(), str.end()));
    return result;
}

void matchParensHelper(int leftLPar, int leftRPar, const string& validPara, vector<string>& result  ){
    if(!leftLPar && !leftRPar){
        result.emplace_back(validPara);
        return;
    }
    if(leftLPar){
        matchParensHelper(leftLPar-1, leftRPar, validPara + "(", result);
    }
    if(leftRPar > leftLPar){
        matchParensHelper(leftLPar, leftRPar-1, validPara + ")", result);
    }
}

vector<string> matchParens(int numParen){
    vector<string> result;
    if(numParen > 0){
        matchParensHelper(numParen, numParen, "", result);
    }
    return result;
}






#endif /* recursionDP1_h */
