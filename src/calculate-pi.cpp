#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <chrono>

int main() {
    mpf_set_default_prec(33219280);

    mpf_class pi, sum = 0, term;
    mpz_class factorial = 1, factorial3k = 1, L("13591409"), X("1");
    const mpz_class K("545140134"), M("6403203"), C("426880"), sqrtC("10005");

    auto start = std::chrono::steady_clock::now();

    unsigned long k = 0;
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count() < 60) {
        if (k > 0) {
            // Avoid division by zero by ensuring k is properly incremented and used
            factorial *= k;
            factorial3k *= (3*k - 3)*(3*k - 2)*(3*k - 1);
            L += K;
            X *= -262537412640768000;
        }

        mpf_class numerator = factorial3k * L;
        mpf_class denominator = factorial * factorial * factorial * X;
        if (denominator == 0) {
            std::cerr << "Division by zero detected, terminating loop." << std::endl;
            break;
        }
        term = numerator / denominator;

        sum += term;

        k++;
    }

    mpf_class sqrtCValue;
    mpf_sqrt_ui(sqrtCValue.get_mpf_t(), sqrtC.get_ui());
    pi = (C * sqrtCValue) / sum;

    // Calculate and output the estimated number of decimal places
    mp_exp_t exp;
    char *pi_str = mpf_get_str(nullptr, &exp, 10, 0, pi.get_mpf_t());
    std::string piDigits(pi_str);
    int numDecimals = piDigits.length(); // Length of the string representation
    gmp_printf("Pi: %.Ff\n", pi.get_mpf_t());
    std::cout << "Estimated decimal places calculated: " << numDecimals - 1 << std::endl; // Subtract 1 for the digit before the decimal point

    free(pi_str); // Free the allocated memory for the string


    return 0;
}
