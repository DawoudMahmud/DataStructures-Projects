//
//  shell_sort3.cpp
//  
//
//  Created by Dawoud Mahmud on 4/10/21.
//

#include "project1.h"
#include <iostream>
#include <algorithm>

void shell_sort3(std::vector<int>& nums)
{
    std::vector<int> sequence = {1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 27, 32, 36, 48, 54, 64, 72, 81, 96, 108, 128, 144, 162, 192, 216, 243, 256, 288, 324, 384, 432, 486, 512, 576, 648, 729, 768, 864, 972, 1024, 1152, 1296, 1458, 1536, 1728, 1944, 2048, 2187, 2304, 2592, 2916, 3072, 3456, 3888};
    std::reverse(sequence.begin(),sequence.end());

    for (int k = 0; k < sequence.size(); ++k)
        {
            int gap = sequence[k];
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
