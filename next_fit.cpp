//
//  next_fit.cpp
//  
//
//  Created by Dawoud Mahmud on 5/1/21.
//

#include <stdio.h>
#include <iostream>
#include "project2.h"

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
    free_space.push_back(1-items[0]);
    assignment[0] = 1;
    for(int i = 1; i < items.size(); ++i)
    {
        if(items[i] <= free_space[free_space.size()-1])
        {
            free_space[free_space.size()-1] -= items[i];
            assignment[i] = assignment[i-1];
        }
        else
        {
            assignment[i] = assignment[i-1] + 1;
            free_space.push_back(1-items[i]);
        }
    }
}

//int main()
//{
//    std::vector<double> items {0.1, 0.8, 0.3, 0.5, 0.7, 0.2, 0.6, 0.4};
//    std::vector<int> assignments(items.size(), 0);
//    std::vector<double> free_space;
//    next_fit(items, assignments, free_space);
//    for(int i = 0; i < free_space.size(); ++i)
//    {
//        std::cout << "assignment " << free_space[i] << std::endl;
//    }
//}
