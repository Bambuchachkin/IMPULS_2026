#include "Noise.h"

void Noise::Make_Noise(std::vector<std::complex<double>>& symbols, double variance) {
    std::normal_distribution<double> delta(0.0, std::sqrt(variance));
    for (auto& sym : symbols) {
        double i = delta(rand_gen);
        double q = delta(rand_gen);
        sym += std::complex<double>(i, q);
    }
}