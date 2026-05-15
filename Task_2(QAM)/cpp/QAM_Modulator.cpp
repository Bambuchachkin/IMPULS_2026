#include "QAM_Modulator.h"
#include "Generator.h"

QAM_Modulator::QAM_Modulator(int Degree) : degree(Degree), constellation(Generate(Degree)) {
    symbol_size = 0;
    int i = degree;
    while (i>1) {
        i = i >> 1;
        symbol_size++;
    }
}

static int symbol_number(const std::vector<bool>& bits, int start, int count) {
    int number = 0;
    for (int i = 0; i < count; ++i)
        number = (number << 1) | bits[start + i];
    return number;
}

std::vector<std::complex<double>> QAM_Modulator::Modulate(const std::vector<bool>& bits) const {
    std::vector<std::complex<double>> symbols;
    int length = bits.size()/symbol_size;

    for (int i = 0; i<length; i++) {
        symbols.push_back(constellation[symbol_number(bits, i * symbol_size, symbol_size)].second);
    }
    return symbols;
}

int QAM_Modulator::get_Symbol_Size() const {
    return symbol_size;
}

const std::vector<std::pair<std::vector<bool>, std::complex<double>>>& QAM_Modulator::get_Constellation() const {
    return constellation;
}