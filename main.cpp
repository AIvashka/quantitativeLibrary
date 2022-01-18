#include <random>
#include <iostream>
#include <vector>
#include "distributions.h"

int main()
{
    std::vector<int> poissonDistribution = distributions::GetPoissonSample(100, 5);
    for (auto &value : poissonDistribution) {
        std::cout << value << " ";
    }
    return 0;
}