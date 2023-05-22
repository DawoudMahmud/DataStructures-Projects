
//
//  shell_sort1.cpp
//
//
//  Created by Dawoud Mahmud on 4/10/21.
//

#include "project1.h"
#include <iostream>

void shell_sort1(std::vector<int>& nums)
{
    for (int gap = (nums.size() / 2); gap > 0; gap /= 2)
    {
        for(int i = gap; i < nums.size(); ++i)
        {

            for(int j = i; j >= gap; j-=gap)
            {
                if(nums[j] < nums[j-gap])
                {
                    int temp = nums[j-gap];
                    nums[j-gap] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
}

