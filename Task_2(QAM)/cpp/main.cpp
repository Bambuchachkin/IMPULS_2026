#include <iostream>
#include <fstream>
#include <random>
#include "QAM_Modulator.h"
#include "QAM_Demodulator.h"
#include "Noise.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Enter modulation degree (4, 16, 64)\n";
        return 1;
    }
    int degree = std::stoi(argv[1]);
    if (degree != 4 && degree != 16 && degree != 64) {
        std::cerr << "Invalid degree (use 4, 16, 64)\n";
        return 1;
    }
    int N_BITS = 1000000;

    std::mt19937 rand_gen(std::random_device{}());
    std::uniform_int_distribution<int> bit_gen(0, 1);
    std::vector<bool> bits(N_BITS);
    for (int i = 0; i < N_BITS; i++)
        bits[i] = bit_gen(rand_gen);

    QAM_Modulator modulator(degree);
    QAM_Demodulator demodulator(degree);
    Noise noise_maker;

    int s_size = modulator.get_Symbol_Size();
    N_BITS = (N_BITS / s_size) * s_size;
    std::vector<bool> tx_bits(bits.begin(), bits.begin() + N_BITS);
    auto symbols_no_noise = modulator.Modulate(tx_bits);

    std::vector<double> variances;
    for (double v = 0.01; v <= 10.0; v *= 1.2)
        variances.push_back(v);

    std::ofstream fout("CSV/ber_variance_"+ std::to_string(degree) +".csv");
    fout << "variance,ber\n";
    for (double v : variances) {
        auto symbols = symbols_no_noise;
        noise_maker.Make_Noise(symbols, v);
        auto rx_bits = demodulator.Demodulate(symbols);

        int errors = 0;
        for (int i = 0; i < N_BITS; i++)
            if (tx_bits[i] != rx_bits[i]) errors++;

        double BER = static_cast<double>(errors)/N_BITS;
        fout << v << "," << BER << "\n";
        // std::cout << "variance = " << v << ", BER = " << BER << "\n";
    }
    fout.close();
    std::cout << "Saved in CSV/ber_variance_"+ std::to_string(degree) +".csv\n";
    return 0;
}
