//
//  stackExample.h
//  recursionAndDP
//
//  Created by shashank hegde on 6/22/16.
//  Copyright © 2016 shashank hegde. All rights reserved.
//

#ifndef stackExample_h
#define stackExample_h
#include <vector>
#include <stack>
using namespace std;

    
    void sortStk(stack<int>& mainStk){
        if(mainStk.empty()){
            return;
        }
        else{
            stack<int> auxStk;
            int count = 0;
            while(count < mainStk.size()){
                int maxValue = mainStk.top();
                // mainStk.pop();
                while(mainStk.size() > count){
                    if(mainStk.top() > maxValue){
                        maxValue = mainStk.top();
                    }
                    auxStk.push(mainStk.top());
                    mainStk.pop();
                }
                mainStk.push(maxValue);
                bool maxSeen = false;
                while(!auxStk.empty()){
                    if(maxValue == auxStk.top() && !maxSeen){
                        maxSeen = true;
                    }
                    else{
                        mainStk.push(auxStk.top());
                    }
                    auxStk.pop();
                }
                count++;
            }
        }
    }
    
    
    



#endif /* stackExample_h */
