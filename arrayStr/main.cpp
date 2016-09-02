//
//  main.cpp
//  arraysStr
//
//  Created by shashank hegde on 2/12/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include "rotate2Darr.hpp"
#include <algorithm>
void vectStr(vector<int> &A){
    for(int i=0; i<A.size(); i++){
        cout << A[i] << endl;
    }
}

int removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() < 2){
        return A.size();
    }
    sort(A.begin(), A.end());
    int prev = A[0];
    size_t counter = 1;
    while(counter < A.size()){
        if(A[counter] == prev){
            int temp = counter;
            while(counter < A.size() && A[counter] == prev){
                counter++;
            }
            A.erase(std::remove(A.begin(), A.end(), prev), A.end());
            A.insert(A.begin()+temp-1, prev);
            counter = temp;
            //vectStr(A);
        }
        prev =  A[counter];
        counter++;
    }
    sort(A.begin(), A.end());
    return A.size();
}

int maxOneHelperStart(const vector<int> &A, int start, int end, int flipsLeft){
    int oneCounter = 0;
    while(start <= end || flipsLeft > 0 ){
        if(A[start] == 1){
            oneCounter++;
        }
        else{
            if(!flipsLeft){
                break;
            }
            flipsLeft--;
            oneCounter++;
        }
        start++;
    }
    return oneCounter;
}

int maxOneHelperEnd(const vector<int> &A, int start, int end, int flipsLeft){
    int oneCounter = 0;
    while(start <= end || flipsLeft > 0 ){
        if(A[end] == 1){
            oneCounter++;
        }
        else{
            if(!flipsLeft){
                break;
            }
            flipsLeft--;
            oneCounter++;
        }
        end--;
    }
    return oneCounter;
}


vector<int> maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    
    if(B > A.size()){//base condition
        for(int i=0; i<A.size();i++){
            result.emplace_back(i);
        }
        return result;
    }
    int numZeros = 0;
    int counter=0;
    
    //cout << "numZeros:" << numZeros << endl;
    
    int i=0, j=0;
    size_t endCount = A.size()-1;
    while(i < A.size()){
        numZeros = count(A.begin()+j, A.begin() + endCount+1, 0);
        if(numZeros > B){
            int oneRedEnd = maxOneHelperStart(A, j, endCount-1, B );
            int oneIncStart = maxOneHelperEnd(A, j+1, endCount, B);
            if(oneIncStart <= oneRedEnd ){
                endCount--;
            }
            else {
                j++;
            }
        }
        else{
            break;
        }
        i++;
    }
    for(int x=j; x<=endCount; x++){
        result.emplace_back(x);
    }
    return result;
}




int main(int argc, const char * argv[]) {
    // insert code here...
   /* vector<vector<int>> arr = {
        {0,1, 2, 3, 4, 5, 6, 7},
        {5,6, 7, 8, 9, 10, 11, 12},
        {17,16, 15, 3, 4, 14, 13, 12},
        {18,25, 46, 56, 47, 52, 61, 17},
        {30,61, 22, 33, 44, 45, 46, 17},
        {20,51, 2, 3, 4, 5, 6, 7},
        {90,61, 2, 3, 4, 5, 6, 7},
        {100,71, 2, 3, 4, 5, 6, 7}
    };
    
    rotate2DArr(arr);
    arrStr(arr);*/
    //vector<int> arr1 = {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
    vector<int> arr1 = {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0};
    arr1 = maxone(arr1, 4);
    vectStr(arr1);
    return 0;
}
