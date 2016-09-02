//
//  main.cpp
//  intervalBinSearch
//
//  Created by shashank hegde on 4/2/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

vector<vector<int> > levelOrder(TreeNode* A) {
    // Do not write main() function.
vector<vector<int>> result;
if(!A){
    return result;
}
int level = 0;
vector<int> curr(1, A->val);
vector<TreeNode*> pNodes;
pNodes.emplace_back(A);
result.emplace_back(A);
int prev_level = 0;
while(!pNodes.empty()){
    vector<int> childVal;
    vector<TreeNode*> cNodes;
    for(TreeNode* node: pNodes){
        if(node->left){
            cNodes.emplace_back(node->left);
            childVal.emplace_back(node->left->val);
        }
        if(node->right){
            cNodes.emplace_back(node->right);
            childVal.emplace_back(node->right->val);
        }
    }
    result.emplace_back(childVal);
    //pNodes = cNodes;
}
return result;
}



vector<int> searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> result(2, -1);
    if(A.size() == 1 ){
        return A[0] == B ? vector<int>(2,0) : result;
    }
    int left = 0, right = A.size()-1;
    bool hasGoneLeft = false;
    while(left < right){
    /*    cout << "left=" << left << " right=" << right << endl;
        if(A[left] == B && ((left > 1 && A[left-1] != B) || A[left] == 0 )){
            result[0] = left;
        }
        if(A[right] == B && ((right < A.size()-1 && A[right+1] != B) || right == A.size()-1 ) ) {
            result[1] = right;
        }
        cout << result[0] << "," << result[1] << endl;
     
        if(result[0] != -1 && result[1] != -1){
            return (result[0] == result[1]) ? vector<int>(2, -1) : result;
        } */
        int mid = left + (right-left)/2;
        cout << "mid=" << mid << "value=" << A[mid] << endl;
        if(A[mid] < B){
            left = mid +1;
        }
        else if(A[mid] >= B){
            right = mid;
        }
        
    }
    if(A[right] != B){
        return {-1, -1};
    }
    int start = right;
    result[0] = right;
    cout << "start of the sequence is:" << start << " value is:" << A[start] << endl;
    if(start < (A.size()-1) && A[start+1] == A[start]){
        left = start, right = A.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(A[mid] == B && ((mid+1 < (A.size()-1) && A[mid+1] != A[mid]) || mid+1 == A.size())){
                result[1] = mid;
                cout << "start of the sequence is:" << start << " value is:" << A[start] << endl;
                return result;
            }
            if(A[mid] > B){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        if(A[right] == B){
            result[1] = right;
        }
    }
    else{
        return {start, start};
    }
    return result;
}

int knightHelper(int N, int M, int x1, int y1, int x2, int y2, vector<vector<int>>& possPos ){
    cout << "x1=" << x1 << " y1=" << y1 << " x2=" << x2 << " y2=" << y2 << endl;
    
    if(x1<0 || x1 > N || y1 <0 || y1 > M ){
        return -1;
    }
    if(x1 == x2 && y1 == y2){
        return 0;
    }
    if(x1 == x2 && y1 != y2){
        return -1;
    }
    if(x1 != x2 && y1 == y2){
        return -1;
    }
    int minSteps = 0;
    if(possPos[x1][y1]){
        return possPos[x1][y1];
    }
    if(x1+2 < N && y1+1 < M){
        if(!possPos[x1+2][y1+1]){
            possPos[x1+2][y1+1] = knightHelper(N, M, x1+2, y1+1, x2, y2, possPos);
        }
        minSteps = possPos[x1+2][y1+1] != -1 ? min(minSteps, possPos[x1+2][y1+1]) : minSteps;
    }
    
    if(x1+2 < N && y1-1 >0){
        if(!possPos[x1+2][y1-1]){
            possPos[x1+2][y1-1] = knightHelper(N, M, x1+2, y1-1, x2, y2, possPos);
        }
        minSteps = possPos[x1+2][y1-1] != -1 ? min(minSteps, possPos[x1+2][y1-1]) : minSteps;
    }
    
    if(x1-2 > 0 && y1+1 > M){
        if(!possPos[x1-2][y1+1]){
            possPos[x1-2][y1+1] = knightHelper(N, M, x1-2, y1+1, x2, y2, possPos);
        }
        minSteps = possPos[x1-2][y1+1] != -1 ? min(minSteps, possPos[x1-2][y1+1]) : minSteps;
    }
    
    if(x1 -2 > 0 && y1 + 1 < M){
        if(!possPos[x1-2][y1+1]){
            possPos[x1-2][y1-1] = knightHelper(N, M, x1-2, y1-1, x2, y2, possPos);
        }
        minSteps = possPos[x1-2][y1-1] != -1 ? min(minSteps, possPos[x1-2][y1-1]) : minSteps;
    }
    if(x1+1 < N && y1+2 < M){
        if(!possPos[x1+1][y1+2]){
            possPos[x1+1][y1+2] = knightHelper(N, M, x1+1, y1+2, x2, y2, possPos);
        }
        minSteps = possPos[x1+1][y1+2] != -1 ? min(minSteps, possPos[x1+1][y1+2]) : minSteps;
    }
    if(x1+1 < N && y1-2 > 0){
        if(!possPos[x1+1][y1-2])
            possPos[x1+1][y1-2] = knightHelper(N, M, x1+1, y1-2, x2, y2, possPos);
        minSteps = possPos[x1+1][y1-2] != -1 ? min(minSteps, possPos[x1+1][y1-2]) : minSteps;
    }
    
    if(x1-1 > 0 && y1-2 > 0){
        if(!possPos[x1-1][y1-2]){
            possPos[x1-1][y1-2] = knightHelper(N, M, x1-1, y1-2, x2, y2, possPos);
        }
        minSteps = possPos[x1-1][y1-2] != -1 ? min(minSteps, possPos[x1-1][y1-2]) : minSteps;
    }
    
    if(x1-1 > 0 && y1+2 < M){
        if(!possPos[x1-1][y1+2]){
            possPos[x1-1][y1+2] = knightHelper(N, M, x1-1, y1+2, x2, y2, possPos);
        }
        minSteps = possPos[x1-1][y1+2] != -1 ? min(minSteps, possPos[x1-1][y1+2]) : minSteps;
    }
    
    if(minSteps == 0){
        possPos[x1][y1] = -1;
    }
    else{
        possPos[x1][y1] = 1 + minSteps;
    }
    return possPos[x1][y1];
}


int knight(int N, int M, int x1, int y1, int x2, int y2) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(x2 > N || x2 < 0 || y2 > M || y2 < 0 ){
        return -1;
    }
    vector<vector<int>> possPos(N, vector<int>(M, 0));
    //knightHelper(N, M, x1-1, y1-1, x2-1, y2-1, possPos);
    return possPos[x2-1][y2-1];
}




int main(int argc, const char * argv[]) {
    // insert code here...
   /* vector<int> lst= { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    
    vector<int> result = searchRange(lst, 3);
    cout << "start=" << result[0] << " end=" << result[1] << endl;
    */
    int minSteps = knight(8, 8, 1, 1, 8, 8);
    cout << "minsteps=" << minSteps << endl;
    return 0;
}
