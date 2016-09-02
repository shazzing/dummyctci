//
//  main.cpp
//  wordBreaking
//
//  Created by shashank hegde on 3/6/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> wordBreaking(string s, const unordered_set<string> dict){
    // T[i] is the  length of the last decomposition of s(0,i)
    vector<int> T(s.size(), 0);
    for(size_t i =0; i<s.size(); i++){
        if(dict.find(s.substr(0, i+1)) != dict.cend()){
            T[i] = i+1;
        }
        
        // sets T[i] if T[j] != 0 and s(j+1, i) is a valid string
        for(int j=0; j<i; j++){
            if(T[j] != 0 && dict.find(s.substr(j+1,i-j)) != dict.cend() ){
                T[i] = i-j;
            }
        }
    }
    
    vector<string> ret;
    if(T.back()){
        int idx = s.size() -1;
        while(idx >= 0){
            ret.emplace_back(s.substr(idx - T[idx] + 1, T[idx]));
            idx -= T[idx];
        }
        reverse(ret.begin(), ret.end());
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    unordered_set<string> dict = {"bat", "bed", "hand", "beyond" };
    
    vector<string> ret = wordBreaking("bedbathandbeyond", dict);
    for(string s: ret){
        cout << s << endl;
    }
    return 0;
}
