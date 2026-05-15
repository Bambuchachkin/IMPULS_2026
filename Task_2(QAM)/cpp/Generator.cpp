#include "Generator.h"
#include <stdexcept>
#include <cmath>

std::vector<std::pair<std::vector<bool>, std::complex<double>>> Generate(int degree) {
    std::vector<std::pair<std::vector<bool>, std::complex<double>>> constellation;
    int symbol_size = 0;
    int d = degree;
    while (d>1) {
        d = d >> 1;
        symbol_size++;
    }
    int ss_2 = symbol_size / 2;
    int max_level = 1 << ss_2;
    double mean_E = (2.0 / 3.0) * (degree - 1);
    double scale = 1.0 / std::sqrt(mean_E);

    int gray = 0;
    std::vector<int> PAM(max_level);
    for (int i = 0; i < max_level; i++) {
        gray = i ^ (i >> 1);
        PAM[gray] = (max_level - 1) - 2 * i;
    }

    std::vector<bool> bits(symbol_size);
    for (int i = 0; i < degree; i++) {
        int tmp = i;
        for (int j = 0; j < symbol_size; j++) {
            bits[symbol_size - 1 - j] = tmp & 1;
            tmp >>= 1;
        }

        int i_ = 0, q_ = 0;
        for (int j = 0; j < ss_2; j++) {
            i_ = (i_ << 1) | bits[j];
            q_ = (q_ << 1) | bits[ss_2 + j];
        }

        double real = PAM[i_] * scale;
        double imag = PAM[q_] * scale;
        constellation.emplace_back(bits, std::complex<double>(real, imag));
    }
    return constellation;
}