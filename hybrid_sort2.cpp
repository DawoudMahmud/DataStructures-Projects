//
//  hybrid_sort2.cpp
//  
//
//  Created by Dawoud Mahmud on 4/10/21.
//
#include "project1.h"
#include <iostream>
#include <math.h>

void hybrid_sort2(std::vector<int>& nums)
{
        int h = pow(nums.size(), 1.0/4);
    std::cout << "HIS: " << h << std::endl;
        if(nums.size() > h) //merge sort
        {
            merge_sort(nums);
        }
        else //insertion sort
        {
           insertion_sort(nums);
        }
}
