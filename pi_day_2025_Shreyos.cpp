// Implementing the calculation of Pi using naive(without optimizations) Chudnovsky Algorithm

#include <iostream>
#include <cmath>
#include <iomanip>

long double factorial(int n) {

    if (n == 0)
        return 1;

    long double result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

long double compute_pi(int terms) {

    long double sum = 0;

    for (int i = 0; i < terms; i++) {

        long double numerator = factorial(6 * i) * (545140134 * i + 13591409);

        numerator *= (i % 2 == 0) ? 1.0 : -1.0;

        long double denominator = factorial(3 * i) * pow(factorial(i), 3) * pow(640320, (3 * i) + 1.5);

        sum += (numerator / denominator);
    }

    return 1.0 / (sum * 12.0);
}

int main() {

    int terms = 5;
    std::cout << std::setprecision(30) << "The approximation of Pi is: " << compute_pi(terms) << std::endl;
    std::cin.get();

    return 0;

}