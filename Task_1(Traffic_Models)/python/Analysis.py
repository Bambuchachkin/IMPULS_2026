import argparse
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path

def analyze(file_name):
    model_name = Path(file_name).stem.title()
    df = pd.read_csv(file_name, names=['time', 'size'])
    times = df['time'].values
    sizes = df['size'].values

    avg_size = np.mean(sizes)
    total_bytes = np.sum(sizes)
    total_time = times[-1] - times[0]
    avg_bitrate = (total_bytes * 8) / total_time
    delays = np.diff(times)
    avg_delay = np.mean(delays)

    print(f"Traffic Model: {model_name}")
    print(f"Average packet size: {avg_size:.2f} bytes")
    print(f"Average bitrate: {avg_bitrate:.2f} bits/sec")
    print(f"Average inter-arrival delay: {avg_delay:.6f} sec")

    Bins = 'auto'
    if 'Uniform' in model_name:
        Bins = 1000

    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.hist(delays, bins=Bins, edgecolor='black', alpha=0.7)
    plt.xlabel('Inter-arrival time (s)')
    plt.ylabel('Frequency')
    plt.title(f'Delay histogram ({model_name})')
    plt.grid(True, linestyle='--', alpha=0.5)

    if 'Uniform' in model_name:
        plt.subplot(1, 2, 2)
        unique_sizes, counts_sizes = np.unique(sizes, return_counts=True)
        width_size = max(0.01, unique_sizes[0] * 0.1 if unique_sizes[0] != 0 else 0.1)
        plt.bar(unique_sizes, counts_sizes, width=width_size, edgecolor='black', color='orange')
        plt.xlabel('Packet size (bytes)')
        plt.ylabel('Frequency')
        plt.title(f'Size (uniform)')
        plt.grid(True, linestyle='--', alpha=0.5)
    else:
        plt.subplot(1, 2, 2)
        plt.hist(sizes, bins=Bins, edgecolor='black', alpha=0.7, color='orange')
        plt.xlabel('Packet size (bytes)')
        plt.ylabel('Frequency')
        plt.title(f'Packet size histogram ({model_name})')
        plt.grid(True, linestyle='--', alpha=0.5)

    plt.tight_layout()

    plot_path = Path(file_name).with_suffix('.png')
    plt.savefig(plot_path, dpi=150)
    print(f"Plot saved to {plot_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("csv_file", help="CSV file from C++ traffic model")
    args = parser.parse_args()
    analyze(args.csv_file)