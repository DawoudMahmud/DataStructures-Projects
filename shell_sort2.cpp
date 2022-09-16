//
//  shell_sort2.cpp
//  
//
//  Created by Dawoud Mahmud on 4/10/21.
//

#include "project1.h"
#include <iostream>
#include <math.h>

void shell_sort2(std::vector<int>& nums)
{
    int k = log(nums.size());
    std::vector<int> sequence;
    for(int i = k; i >0; --i)
    {
        sequence.push_back(pow(2,i) + 1); //sequence is filled with 2^k+1 for k = log(n) ...2,1
    }
    sequence.push_back(1); //append 1 at the end
    for (int j = 0; j < sequence.size(); ++j)
        {
            int gap = sequence[j];
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
