#include "QAM_Demodulator.h"
#include "Generator.h"

QAM_Demodulator::QAM_Demodulator(int degree) : degree(degree), constellation(Generate(degree)) {
    symbol_size = 0;
    int i = degree;
    while (i>1) {
        i = i >> 1;
        symbol_size++;
    }
}

double Norm(const std::complex<double>& z) {
    double r = z.real();
    double i = z.imag();
    return r * r + i * i;
}

std::vector<bool> QAM_Demodulator::Demodulate(const std::vector<std::complex<double>>& symbols) const {
    std::vector<bool> bits;
    int nearest_symbol = 0;
    double min_distance = 0;
    double current_distance = 0;
    for (const auto& sym : symbols) {
        min_distance = Norm(sym - constellation[0].second);
        for (int i = 1; i < degree; ++i) {
            current_distance = Norm(sym - constellation[i].second);
            if (current_distance < min_distance) {
                min_distance = current_distance;
                nearest_symbol = i;
            }
        }
        const auto& bits_v = constellation[nearest_symbol].first;
        bits.insert(bits.end(), bits_v.begin(), bits_v.end());
    }
    return bits;
}