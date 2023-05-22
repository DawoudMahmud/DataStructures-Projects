//
//  hybrid_sort3.cpp
//  
//
//  Created by Dawoud Mahmud on 4/10/21.
//
#include "project1.h"
#include <iostream>
#include <math.h>

void hybrid_sort3(std::vector<int>& nums)
{
        int h = pow(nums.size(), 1.0/6);
        if(nums.size() > h) //merge sort
        {
            merge_sort(nums);
        }
        else //insertion sort
        {
           insertion_sort(nums);
        }
}
