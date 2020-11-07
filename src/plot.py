import os
import numpy as np
import matplotlib.pyplot as plt

stats_files = os.listdir("../random/stats")
stats_files.sort()   # 100 1000 10000 100000 5000 50000 500000 75000

algos_stats = [[] for i in range(5)]
for i in range(8):
    stats_file = open(f'../random/stats/{stats_files[i]}', "r")
    stats_list = stats_file.readlines()
    stats_list = [float(x.strip()) for x in stats_list]
    for j in range(5):
        algos_stats[j].append(stats_list[j])

bar_width = 0.1
x = np.arange(8)
colors = ['b', 'g', 'r', 'c', 'm']
labels = ['Selection', 'Insertion', 'Merge', 'Quick', 'Hybrid']
for i in range(5):
    plt.bar(x+i*bar_width,
            algos_stats[i], color=colors[i], width=bar_width, label=labels[i], edgecolor='grey')

plt.yscale('log')
plt.title('Performance on random generated datasets', fontweight='bold')
plt.xlabel('Dataset Size', fontweight='bold')
plt.ylabel('Time in milliseconds', fontweight='bold')
plt.xticks(x+2*bar_width, ['100', '1000',
                           '10000', '100000', '5000', '50000', '500000', '75000'])
plt.legend()
plt.show()
