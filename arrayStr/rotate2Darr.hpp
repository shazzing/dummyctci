//
//  rotate2Darr.cpp
//  arraysStr
//
//  Created by shashank hegde on 2/12/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void arrStr(const vector<vector<int>>& arr){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate2DArr(vector<vector<int>>& arr){
    size_t sz = arr.size();
    for(int layer=0; layer < sz/2; layer++){
        int first = layer;
        int last = sz-1-layer;
        for(int i=first; i<last; i++){
            int offset = i-first; // determine how back from last is the element.
            int top = arr[first][i]; // save top left
            // bottom left column to top left row
            arr[first][i] = arr[last-offset][first];
            
            // bottom right row to bottom left column
            arr[last - offset][first] = arr[last][last-offset];
            
            // top right column to bottom right row
            arr[last][last-offset] = arr[i][last];
            
            arr[i][last] = top;
        }
    }
    
        }
