//
//  main.cpp
//  graphParse
//
//  Created by shashank hegde on 4/9/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


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
    knightHelper(N, M, x1-1, y1-1, x2-1, y2-1, possPos);
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

