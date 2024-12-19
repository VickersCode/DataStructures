
## Assignment Goals
The goal of this project is to:
1.	Familiarize students with **sorting**
2.  Apply **time complexity** analysis.

## Problem
Let's measure the performance of different sorting algorithms!

## Requirements
### Overview
- generate 3 sets of random numbers, each a different size
- implement three sorting algorithms
  - use them to sort the random numbers
  - use them to sort the sorted numbers
  - save measurements of 3 metrics
- use the measurements to create graphs

### Number Sets
Your program should generate 3 sets of random integer values in the range of 0 to 1,000,000. Each set of random numbers should be a different size:
1. 1,000
2. 10,000
3. 100,000.

This will help us analyze the performance of the algorithms as the size of the problem grows.  

You'll also need to save a sorted copy of each sized set (it's fine if you generate this by running one of your sorts over the original random sets). This will help highlight which sorts actually perform worse on data that's already sorted!  

Altogether, there are 6 sets of numbers to go through our sorting algorithms: 3 sizes and 2 categories (sorted or unsorted).

### Sorting Algorithm
Your program should implement three sorting algorithms.  
**One algorithm MUST be insertion sort.**  
Another algorithm should be either of the following:
- selection sort
-	bubble sort  

The final algorithm should be either of the following:
-	merge sort
-	quick sort 

### Data Analysis
#### Raw Measurements - save the metric measurements to one or more files:
- each sorting algorithms should sort each set of numbers (unsorted and sorted) 10 times
  - that's a total of 20 runs per algorithm and data size
- the following metric measurements should be saved each time the algorithm is run over a data set
  -	the CPU time (use the same machine)
  -	the number of comparisons
  -	the number of swaps  
-	see the example data files for an example

#### Graphs - create graphs to compare each algorithm's metric as the size of the data grows:
- There should be a graph for every metric and category of data
  -	use the ***average*** of the 10 runs for each algorithm, data size, category, measurement
  -	each graph has 3 lines
-	for example, **CPU Time** for the **Unsorted** data
    -	the X-axis: each algorithm's average measurement for the metric
    -	the Y-axis: data size 
-	see the example data files for an example
     
### Deliverables
-	Source code for any classes you include
-	A *modular* main driver
-	a makefile
- 180 raw measurement values in one or more files
  - A combination of
    - 3 sorting algorithms
    - 10 runs to get the average
    - 3 metric measurements per run
    - 3 sizes
    - 2 categories (sorted or unsorted)
  - A .csv file is just a "comma separated" file
    - If you use that file extension and a comma between the data when saving the data from your program, it will automagically have rows and columns when you open it with Excel
- 6 Graphs in one or more files
  - It's easy to convert .csv files to .xlsx files in Excel just by using the "Save As" option

Please see the example output files in this repository for more information.  
### Helpful Resources
- Measuring execution timing
  - https://www.geeksforgeeks.org/measure-execution-time-function-cpp
- Generating random numbers
  - https://www.bitdegree.org/learn/random-number-generator-cpp
  - https://en.cppreference.com/w/cpp/numeric/random/rand

## Extra Credit
### Features will **ONLY** be considered for extra credit if the required functionality is *completely* implemented.  
You may implement all 5 algorithms for extra credit up to 5% (2.5% for each sort). To receive extra credit for this work, indicate which are your 3 main algorithms and which 2 are extra credit. The 3 main algorithms must receive full credit for your 2 extra credit algorithms to be considered for credit.
