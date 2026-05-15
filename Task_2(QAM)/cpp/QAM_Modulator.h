#ifndef QAM_MODULATOR_H
#define QAM_MODULATOR_H
#include <complex>
#include <vector>
#include <utility>

class QAM_Modulator {
private:
    int degree;
    int symbol_size;
    std::vector<std::pair<std::vector<bool>, std::complex<double>>> constellation;
public:
    QAM_Modulator(int Degree);
    ~QAM_Modulator() = default;

    std::vector<std::complex<double>> Modulate(const std::vector<bool>& bits) const;
    int get_Symbol_Size() const;
    const std::vector<std::pair<std::vector<bool>, std::complex<double>>>& get_Constellation() const;
};

#endif //QAM_MODULATOR_H
