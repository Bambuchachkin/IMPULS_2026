#ifndef NOISE_H
#define NOISE_H
#include <complex>
#include <vector>
#include <random>

class Noise {
private:
    std::mt19937 rand_gen{std::random_device{}()};
public:
    Noise() = default;
    ~Noise() = default;
    void Make_Noise(std::vector<std::complex<double>>& symbols, double variance);
};

#endif //NOISE_H
