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
    std::vector<int> poisson(int lambda = 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::poisson_distribution<> poisson(lambda);
        std::vector<int> poissonSample;
        for(int i = 0; i < sampleSize; ++i) {
            poissonSample.emplace_back(poisson(gen));
        }
        return poissonSample;
    }

    template <size_t sampleSize>
    std::vector<double> exponential(double lambda = 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> uniform(0.0, 1.0);
        double value;
        double lambdaReciprocal = -1 / lambda;
        std::vector<double> exponentialSample;
        for(int i = 0; i < sampleSize; ++i) {
            value = uniform(gen);
            exponentialSample.emplace_back(lambdaReciprocal * log(1 - value));
        }
        return exponentialSample;
    }

    template <size_t sampleSize>
    std::vector<double> normal(double mean = 0, double std = 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<double> norm(mean, std);
        std::vector<double> normalSample;
        for(int i = 0; i < sampleSize; ++i) {
            normalSample.emplace_back(norm(gen));
        }
        return normalSample;
    }

}


#endif //OPTIONS_DISTRIBUTIONS_H
