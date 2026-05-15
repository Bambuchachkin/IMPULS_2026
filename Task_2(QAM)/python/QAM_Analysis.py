import pandas as pd
import matplotlib.pyplot as plt

# Загрузка данных для трёх видов модуляции
data4 = pd.read_csv('../CSV/ber_variance_4.csv')
data16 = pd.read_csv('../CSV/ber_variance_16.csv')
data64 = pd.read_csv('../CSV/ber_variance_64.csv')

plt.figure(figsize=(8, 6))

# 4-QAM (QPSK)
plt.semilogy(data4['variance'], data4['ber'], 'bo-', markersize=4, label='QPSK (4-QAM)')
# 16-QAM
plt.semilogy(data16['variance'], data16['ber'], 'rs-', markersize=4, label='16-QAM')
# 64-QAM
plt.semilogy(data64['variance'], data64['ber'], 'g^-', markersize=4, label='64-QAM')

plt.grid(True, which='both', ls='--', alpha=0.7)
plt.xlabel('Дисперсия шума (на измерение)')
plt.ylabel('BER')
plt.title('Зависимость BER от дисперсии шума (QAM)')
plt.legend()
plt.tight_layout()
plt.savefig('../CSV/ber_vs_variance_all.png', dpi=150)
