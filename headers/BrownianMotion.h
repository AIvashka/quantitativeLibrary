//
// Created by Alexey Ivashka on 18.01.22.
//

#ifndef OPTIONS_BROWNIANMOTION_H
#define OPTIONS_BROWNIANMOTION_H

#include <vector>
#include <cmath>
#include "Distributions.h"

class BrownianMotion {

public:

    BrownianMotion() : riskFreeRate(0), dividendYield(0), sigma(0), time(0), initialPrice(0) {};

    std::vector<std::vector<double>> generatePaths() const {
        std::vector<std::vector<double>> paths(numberOfPaths);
        for(auto &path : paths) {
            path = generatePath();
        }
        return paths;
    }

    std::vector<double> generatePath() const {

        double dt = time/sampleSize;

        std::vector<double> path;
        path.emplace_back(initialPrice);

        std::vector<double> norm = Distributions::normal<sampleSize>();

        double drift = exp(dt * ((riskFreeRate - dividendYield) - 0.5 * sigma * sigma));
        double vol = sqrt(sigma*sigma*dt);

        for(int i = 1; i < sampleSize; i++){
            path.emplace_back(path[i-1] * drift * exp(vol * norm[i]));
        }
        return path;
    }


private:
    double riskFreeRate;
    double dividendYield;
    double sigma;
    double time;
    double initialPrice;

    static constexpr size_t sampleSize = 100;
    size_t numberOfPaths = 1;


};

#endif //OPTIONS_BROWNIANMOTION_H
