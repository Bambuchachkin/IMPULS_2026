#ifndef QAM_DEMODULATOR_H
#define QAM_DEMODULATOR_H
#include <complex>
#include <vector>
#include <utility>


class QAM_Demodulator {
private:
    int degree;
    int symbol_size;
    std::vector<std::pair<std::vector<bool>, std::complex<double>>> constellation;
public:
    QAM_Demodulator(int degree);
    ~QAM_Demodulator() = default;
    std::vector<bool> Demodulate(const std::vector<std::complex<double>>& symbols) const;

};

#endif //QAM_DEMODULATOR_H
