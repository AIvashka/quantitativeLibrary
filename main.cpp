#include <random>
#include <iostream>
#include <vector>
#include "headers/Distributions.h"

int main()
{
    std::vector<int> poissonDistribution = Distributions::poisson<100>(5);
    for (auto &value : poissonDistribution) {
        std::cout << value << " ";
    }
    return 0;
}