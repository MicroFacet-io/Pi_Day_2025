#include <iostream>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>

boost::multiprecision::cpp_dec_float_100 pi_bbp(int n_terms) 
{
    boost::multiprecision::cpp_dec_float_100 pi = 0.0;

    for (int k = 0; k < n_terms; k++) 
    {
        boost::multiprecision::cpp_dec_float_100 term1 = std::pow(16, k);
        boost::multiprecision::cpp_dec_float_100 term2 = (8 * k + 1);
        boost::multiprecision::cpp_dec_float_100 term3 = (8 * k + 4);
        boost::multiprecision::cpp_dec_float_100 term4 = (8 * k + 5);
        boost::multiprecision::cpp_dec_float_100 term5 = (8 * k + 6);

        boost::multiprecision::cpp_dec_float_100 term = 1 / term1 *
        (
            4 / term2
            - 2 / term3
            - 1 / term4
            - 1 / term5
        );

        pi += term;
    }

    return pi;
}

int main() {
    int n_terms = 0;
    std::cout << "Enter the number of terms to approximate pi: ";
    std::cin >> n_terms;

    boost::multiprecision::cpp_dec_float_100 approx_pi = pi_bbp(n_terms);

    std::cout << std::fixed << std::setprecision(75);
    std::cout << "Approximated value of pi using " << n_terms 
              << " terms: " << approx_pi << std::endl;
    
    return 0;
}
