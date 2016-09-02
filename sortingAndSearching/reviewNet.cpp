//
//  main.cpp
//  reviewNet
//
//  Created by shashank hegde on 4/10/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool isValid(pair<int,int> maxRange, pair<int,int> newPair){
    if(newPair.first >= 0 && newPair.first < maxRange.first
       && newPair.second >= 0 && newPair.second < maxRange.second)
        return true;
    return false;
}
struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

int knightHelper(const pair<int,int>& maxRange, pair<int,int> srcPr, pair<int,int> destPr,
                 vector<pair<int, int>> nextCombInd){
    queue<pair<pair<int, int>, int>> nextElemDist;
    unordered_set<pair<int, int>, pairhash> seenElems;
    
    int minStep = numeric_limits<int>::max();
    nextElemDist.emplace(make_pair(srcPr, 0));
    seenElems.emplace(srcPr);
    while(!nextElemDist.empty()) {
        pair<pair<int, int>, int> currElem = nextElemDist.front();
        nextElemDist.pop();
        if(currElem.first.first == destPr.first && currElem.first.second == destPr.second
           && currElem.second < minStep){
            minStep = currElem.second;
        }
        int dist = currElem.second + 1;
        for(auto& nextComb : nextCombInd ){
            pair<int, int> nextSrc = {currElem.first.first + nextComb.first, currElem.first.second+ nextComb.second};
            if(isValid(maxRange, nextSrc)){
                cout << "valid nextPair:{" << nextSrc.first << ", " << nextSrc.second << " }. dist=" << dist
                 << endl;
                if(seenElems.emplace(nextSrc).second){
                    cout << "adding this node to Q" << endl;
                    nextElemDist.emplace(make_pair(nextSrc,dist));
                }
            }
        }
    }
    return minStep == numeric_limits<int>::max() ? -1 : minStep;
}

vector<int> incArbPrecision(vector<int>& A){
    ++A.back();
    for(int i =A.size()-1; i>0 && A[i] == 10; i--){
        A[i] = 0, A[i-1]++;
    }
    if(A[0] == 10){
        A[0] =0;
        A.insert(A.begin(), 1);
    }
    return A;
}

int main(int argc, const char * argv[]) {
   
    vector<pair<int, int>> nextComdInd = {{2,1}, {2, -1}, {-2, 1},
        {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
    /*
     (x + 2, y + 1)
     (x + 2, y - 1)
     (x - 2, y + 1)
     (x - 2, y - 1)
     (x + 1, y + 2)
     (x + 1, y - 2)
     (x - 1, y + 2)
     (x - 1, y - 2)
     */
    
    //vector<vector<int>> possPos(N, vector<int>(M, 0));
    /*int minSteps = -1;
    int val = knightHelper(make_pair(8, 8), make_pair(0, 0), make_pair(7, 7), nextComdInd);
    cout << "val = " << val << endl;
     */
    vector<int> largeInt = {9, 9, 9};
    vector<int> nextLargeInt = incArbPrecision(largeInt);
    for(int a:nextLargeInt){
        cout << a ;
    }
    cout << endl;
    return 0;
}
