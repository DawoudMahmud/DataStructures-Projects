//
//  shell_sort4.cpp
//  
//
//  Created by Dawoud Mahmud on 4/10/21.
//

#include "project1.h"
#include <iostream>
#include <algorithm>
void shell_sort4(std::vector<int>& nums)
{
    std::vector<long> sequence = {    1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305, 260609, 587521, 1045505, 2354689, 4188161, 9427969, 16764929, 37730305, 67084289, 150958081, 268386305, 603906049, 1073643521, 2415771649, 4294770689, 9663381505, 17179475969};
    std::reverse(sequence.begin(),sequence.end());

    for (int k = 0; k < sequence.size(); ++k)
        {
            long gap = sequence[k];
            for(long i = gap; i < nums.size(); ++i)
            {

                for(long j = i; j >= gap; j-=gap)
                {
                    if(nums[j] < nums[j-gap])
                    {
                        long temp = nums[j-gap];
                        nums[j-gap] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
        }
    
}
