//
//  insertion_sort.cpp
//  
//
//  Created by Dawoud Mahmud on 4/4/21.
//

#include "project1.h"
#include <iostream>

void insertion_sort(std::vector<int>& nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(nums[j] < nums[j-1])
            {
                int temp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
