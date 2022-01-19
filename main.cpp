#include <random>
#include <iostream>
#include <vector>
#include "headers/Distributions.h"
#include "headers/BrownianMotion.h"

int main()
{
    const size_t value = 100;
    std::vector<int> poissonDistribution = Distributions::poisson<value>(5);
    for (auto &value : poissonDistribution) {
        std::cout << value << " ";
    }
    BrownianMotion mot = BrownianMotion({0.01, 0.0, 0.2, 5, 100});
    auto paths = mot.generatePaths();
    int i = 1;
    std::cout << std::endl << "Paths size " << paths.size() << std::endl;
    for (const auto &path : paths) {
        std::cout << "Path " << i << std::endl;
        for (const auto &value : path) {
            std::cout << value << " ";
        }
        ++i;
        std::cout << std::endl;
    }
    return 0;
}