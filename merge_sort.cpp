////
////  merge_sort.cpp
////
////
////  Created by Dawoud Mahmud on 4/4/21.
////
#include "project1.h"
#include <iostream>

std::vector<int> merge(std::vector<int> leftV, std::vector<int> rightV) {
    int lefti = 0; //left vector index
    int righti = 0; //right vector index
    std::vector<int> mergedVec;
    while (lefti < leftV.size() && righti < rightV.size())
    {
        if (leftV[lefti] > rightV[righti]) //add right to merged vec if its value is less
        {
            mergedVec.push_back(rightV[righti]);
            righti++;
        }
        else
        {
            mergedVec.push_back(leftV[lefti]); //add left if less
            lefti++;
        }
    }
    while (righti < rightV.size()) //if left is exhausted fill with right
    {
        mergedVec.push_back(rightV[righti]);
        righti++;
    }
    while (lefti  < leftV.size()) //vice versa
    {
        mergedVec.push_back(leftV[lefti]);
        lefti++;
    }

    return mergedVec;
}

void merge_sort(std::vector<int>& nums) {
    if (nums.size() <= 1)
        return;
    
    int mid = nums.size() / 2;
    std::vector<int> leftVec; //left and right subvectors
    std::vector<int> rightVec;
    for(int i = 0; i < mid; i++) //fill vectors
        leftVec.push_back(nums[i]);
    for(int i = mid; i < nums.size(); i++)
        rightVec.push_back(nums[i]);
    merge_sort(leftVec);
    merge_sort(rightVec);
    nums = merge(leftVec,rightVec);
}
