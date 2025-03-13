// Pi_Monte_Carlo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cmath>
#include <future>
#include <iomanip>
#include <thread>

/**
     Consider a square of 2 units in length a side whose center is placed at origin. Consider
     a quarter circle of 1 unit radius, again whose center is from the origin. Try to find a random 
     point in the first quadrant from (0.0, 1.0) and sample the same and count how many are hitting
     inside the circle out of total points.
*/

inline bool missCircle(double x, double y)
{
    return std::pow(x, 2) + std::pow(y, 2) > 1;
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution dist(0.0, 1.0);

    size_t totalPoints(0), hitPoints(0);
    size_t samples(0);

    std::cout << "Please provide number of samples to run Monte Carlo Simulation to calculate PI: " << std::endl;
    std::cin >> samples;

    double x(0.0), y(0.0);
    for (size_t i = 0; i < samples; ++i)
    {
        x = dist(gen);
        y = dist(gen);

        if (!missCircle(x, y))
            ++hitPoints;
    }

    totalPoints = samples;

    double PI = 4.0 * hitPoints / totalPoints;
    std::cout << "PI = ";
    std::cout << std::setprecision(30) << PI << std::endl;
}
