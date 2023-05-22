//
//  hybrid_sort1.cpp
//  
//
//  Created by Dawoud Mahmud on 4/10/21.
//
#include "project1.h"
#include <iostream>
#include <math.h>

void hybrid_sort1(std::vector<int>& nums)
{
    int h = sqrt(nums.size());
    if(nums.size() > h) //merge sort
    {
        merge_sort(nums);
    }
    else //insertion sort
    {
       insertion_sort(nums);
    }
}
