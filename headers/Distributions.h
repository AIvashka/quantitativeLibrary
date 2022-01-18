//
// Created by Alexey Ivashka on 18.01.22.
//

#ifndef OPTIONS_DISTRIBUTIONS_H
#define OPTIONS_DISTRIBUTIONS_H

#include <random>
#include <vector>
#include <cmath>

namespace Distributions {

    template <size_t sampleSize>
    std::vector<int> poisson(double lambda = 1) {
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standarstad mersenne_twister_engine seeded with rd()
        std::poisson_distribution<> poisson(lambda);
        std::vector<int> poissonSample(sampleSize);
        for(int i = 0; i < sampleSize; ++i) {
            poissonSample.emplace_back(poisson(gen));
        }
    }

    template <size_t sampleSize>
    std::vector<double> exponential(double lambda = 1) {
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standarstad mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);
        double value;
        double lambdaReciprocal = -1 / lambda;
        std::vector<double> exponentialSample(sampleSize);
        for(int i = 0; i < sampleSize; ++i) {
            value = dis(gen);
            exponentialSample.emplace_back(lambdaReciprocal * log(1 - value));
        }
        return exponentialSample;
    }

}

#endif //OPTIONS_DISTRIBUTIONS_H
