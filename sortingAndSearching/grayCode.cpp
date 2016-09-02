//
//  main.cpp
//  grayCode
//
//  Created by shashank hegde on 3/4/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> convertVeStrToInt(vector<string> vecStr){
    vector<int> result;
    for(string str:vecStr){
        cout << "bitStr=" << str << endl;
        int curr =0;
        for(char c:str){
            curr = (curr<<1)|(c-'0');
        }
        result.emplace_back(curr);
    }
    return result;
}


vector<int> grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> resultStr;
    vector<int> result;
    if(A <= 0){
        return result;
    }
    resultStr.emplace_back("0");
    resultStr.emplace_back("1");
    for(size_t i=2; i < (1<<A); i=i<<1){
        for(int j=i-1; j>=0; j--){
            cout << "resultStr[" << j << "]=" << resultStr[j] << endl;
            resultStr.emplace_back(resultStr[j]);
        }
        cout << "resultStrSize=" << resultStr.size() << endl;
        for(int j=0; j<i; j++){
            resultStr[j] = "0" + resultStr[j];
        }
        for(s j=i; j<2*i; j++){
            resultStr[j] = "1" + resultStr[j];
        }
        
    }
    result = convertVeStrToInt(resultStr);
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> result = grayCode(3);
    for(int a:result){
        cout << a << endl;
    }
    return 0;
}
