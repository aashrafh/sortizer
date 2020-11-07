import os
import matplotlib.pyplot as plt


def plot_table(table_data, title, fig_title):
    cols = ['Selection', 'Insertion', 'Merge', 'Quick', 'Hybrid']
    rows = ['100', '1000', '10000', '100000',
            '5000', '50000', '500000', '75000']
    row_colors = ['c' for i in range(8)]
    col_colors = ['c' for i in range(5)]
    cell_colors = [['w' for i in range(5)] for i in range(8)]
    plt.table(cellText=table_data,  rowLabels=rows,
              colLabels=cols, loc='center', cellColours=cell_colors, rowColours=row_colors, colColours=col_colors)
    plt.tick_params(axis='x', which='both', bottom=False,
                    top=False, labelbottom=False)
    plt.tick_params(axis='y', which='both', right=False,
                    left=False, labelleft=False)
    for pos in ['right', 'top', 'bottom', 'left']:
        plt.gca().spines[pos].set_visible(False)
    plt.title(title, fontweight='bold')
    plt.savefig(f'../stats/{fig_title}.png',
                bbox_inches='tight', pad_inches=0.05)


def plot_data(data_path, stats_files, title, fig_title):
    table_data = []
    for i in range(8):
        stats_file = open(f'{data_path}/{stats_files[i]}', "r")
        stats_list = stats_file.readlines()
        stats_list = [float(x.strip()) for x in stats_list]
        table_data.append(stats_list)

    plot_table(table_data, title, fig_title)


stats_files = os.listdir("../random/stats")
stats_files.sort()   # 100 1000 10000 100000 5000 50000 500000 75000
plot_data("../random/stats", stats_files,
          'Performance on random generated datasets(time on ms)', 'random_performance_table.png')

stats_files = os.listdir("../sorted/stats")
stats_files.sort()
plot_data("../sorted/stats", stats_files,
          'Performance on sorted datasets(time on ms)', 'sorted_performance_table.png')
