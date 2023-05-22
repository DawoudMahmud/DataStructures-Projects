//
//  first_fit.cpp
//  
//
//  Created by Dawoud Mahmud on 5/2/21.
//

#include <stdio.h>
#include <iostream>
#include "project2.h"
#include "ZipTree.h"


void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
        free_space.push_back(1-items[0]);
        assignment[0] = 1;
        for(int i = 1; i < items.size(); ++i)
        {
            bool trigger = false;
            for(int j = 0; j < free_space.size(); ++j)
            {
                if(items[i] <= free_space[j])
                {
                    assignment[i] = j+1;
                    free_space[j] -= items[i];
                    trigger = true;
                    
                    break;
                }
            }
            if(!trigger)
            {
                assignment[i] = free_space.size() + 1;
                free_space.push_back(1-items[i]);
            }
        }
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
    
}
