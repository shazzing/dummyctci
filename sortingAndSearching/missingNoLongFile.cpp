//
//  main.cpp
//  missingNoLongFile
//
//  Created by shashank hegde on 2/27/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<bool> boolVec(4000000000, 0);
    vector<int> intVec;
    cout << "size of bool vec is: " << (sizeof(boolVec) + sizeof(bool)*boolVec.size())/8 << " bytes" << endl;
    cout << "max size of bool vec is " << boolVec.max_size() << endl;
    
    cout << "size of bool vec is: " << sizeof(intVec) << endl;
    cout << "max size of bool vec is " << intVec.max_size() << endl;
    
    cout << "numeric limit of int is " << numeric_limits<int>::max() << endl;
    return 0;
}
