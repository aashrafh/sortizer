# Sortizer

## 📝 Table of Contents
- [About](#about)
- [Stats](#screenshots)
- [Tools](#tech)
- [Run](#Install)

## 🧐 About <a name = "about"></a>
Implementation of some of the sorting algorithms with an evaluation of the performance of these algorithms and test their performance on large datasets. It's a college assignment for the <strong>CMP302A6: Design and Analysis of Algorithms course</strong> implemented using C++ under Linux.

The implemented algorithms:
- [x] Selection Sort
- [x] Insertion Sort
- [x] Merge Sort
- [x] Quick Sort
- [x] Hybrid Sort

## :bar_chart: Stats 
<div name="screenshots" align="center" width=1189px>
  <p align="center">
    <img src="https://github.com/aashrafh/sortizer/blob/main/stats/random_performance.png" alt="Image Demo" width="500"><br/>
    <img src="https://github.com/aashrafh/sortizer/blob/main/stats/random_performance_table.png.png" alt="Image Demo" width="500"><br/>
    <img src="https://github.com/aashrafh/sortizer/blob/main/stats/sorted_performance.png" alt="Image Demo" width="500"><br/>
    <img src="https://github.com/aashrafh/sortizer/blob/main/stats/sorted_performance_table.png.png" alt="Image Demo" width="500">
  </p>
  </div>

## ⛏️ Built Using <a name = "tech"></a>
- <strong>C++</strong>: Implement the algorithms
- <strong>Python</strong>: Generate the random data, and plot the stats
- <strong>Shell Script</strong>: Automate the test from the terminal


## :computer: Install <a name = "Install"></a>
Open the ```src``` directory and then:
### Automate Test
```
sudo chmod +x ./test.sh
./test.sh
```
### Generate Random Data
```
python runscript.py <size of the data> <path of the output file>
```
Example:
```
python runscript.py 100 data.txt
```
### Compile
```
g++ -O2 sort.cpp
```

### Run
```
./a.out <The algorithm number> <The path of the input file> <The path of the output file> <The path of the stats file>
```
Example:
```
./a.out 1 data.txt sorted_data.txt running_time.txt
```
### Plot
```
python plot_charts.py
python plot_tables.py
```
