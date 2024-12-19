#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void printList(int aList[], int size);
int* copyList(int aList[], int size);
void generateRands(int aList[], int size);
void bubbleSort(int aList[], int size, std::ofstream& fout);
void insertionSort(int aList[], int size);
void insertionSort(int aList[], int size, long long int &comparisons, long long int &swaps);
void dataInsertionSort(int aList[], int size, int numRuns, std::ofstream& fout);
void merge(int aList[], int begin, int mid, int end, long long int& comparisons, long long int& swaps);
void mergeSort(int aList[], int begin, int end, long long int& comparisons, long long int& swaps);
void dataMergeSort(int aList[], int size, int numRuns, std::ofstream& fout);


int main() {
    int TOTAL_RUNS = 10;
    int DEFAULT_SMALL = 1000;
    int DEFAULT_MEDIUM = 10000;
    int DEFAULT_LARGE = 100000;
    
    int smallList[DEFAULT_SMALL];
    int mediumList[DEFAULT_MEDIUM];
    int largeList[DEFAULT_LARGE];

    generateRands(smallList, DEFAULT_SMALL);
    generateRands(mediumList, DEFAULT_MEDIUM);
    generateRands(largeList, DEFAULT_LARGE);

    std::ofstream fout1("bubble1000.csv");
    bubbleSort(smallList, DEFAULT_SMALL - 1, fout1);
    fout1.close();
    std::ofstream fout2("bubble10000.csv");
    bubbleSort(mediumList, DEFAULT_MEDIUM - 1, fout2);
    fout2.close();
    std::ofstream fout3("bubble100000.csv");
    bubbleSort(largeList, DEFAULT_LARGE - 1, fout3);
    fout3.close();

    std::ofstream fout4("insertion1000.csv");
    dataInsertionSort(smallList, DEFAULT_SMALL - 1, TOTAL_RUNS, fout4);
    fout4.close();
    std::ofstream fout5("insertion10000.csv");
    dataInsertionSort(mediumList, DEFAULT_MEDIUM - 1, TOTAL_RUNS, fout5);
    fout5.close();
    std::ofstream fout6("insertion100000.csv");
    dataInsertionSort(largeList, DEFAULT_LARGE - 1, TOTAL_RUNS, fout6);
    fout6.close();

    std::ofstream fout7("merge1000.csv");
    dataMergeSort(smallList, DEFAULT_SMALL - 1, TOTAL_RUNS, fout7);
    fout7.close();
    std::ofstream fout8("merge10000.csv");
    dataMergeSort(mediumList, DEFAULT_MEDIUM - 1, TOTAL_RUNS, fout8);
    fout8.close();
    std::ofstream fout9("merge100000.csv");
    dataMergeSort(largeList, DEFAULT_LARGE - 1, TOTAL_RUNS, fout9);
    fout9.close();


    return 0;
}

void printList(int aList[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << aList[i] << std::endl;
    }
}

int* copyList(int aList[], int size) {
    int* tempList = new int[size];
    for (int i = 0; i < size; i++) {
        tempList[i] = aList[i];
    }
    return tempList;
}

void generateRands(int aList[], int size) { //Function from https://www.bitdegree.org/learn/random-number-generator-cpp
    int DEFAULT_RANGE = 1000000;                                 

    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < size; index++) {
        randomNumber = (rand() % DEFAULT_RANGE) + 1;
        aList[index] = randomNumber;
    }
}

void bubbleSort(int aList[], int size, std::ofstream& fout) {

    std::cout << "\n\n============BUBBLE SORT=================" << std::endl;
    std::cout << "\n\nUnsorted" << std::endl;
    std::cout << std::left 
              << std::setw(12) << "Run Time" 
              << std::setw(12)<< "Comparisons"   
              << std::setw(12)<< "Swaps" << std::endl;
    

    fout << "Run Time" << ", " << "Comparisons" << ", " << "Swaps" << std::endl;
    fout << "Unsorted" << std::endl;

    for (int run = 0; run < 10; ++run) {
        long long int totalComparisons = 0;
        long long int totalSwaps = 0;
        float totalTime = 0;
        int temp = 0;
        long long int comparisons = 0;
        long long int swaps = 0;
        std::chrono::duration<float, std::milli> elapsed_time;

        int* testList = new int[size]; 
        testList = copyList(aList, size);
        

        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) { //we use size - 1 - i because we don't want to iterate through already sorted items
                if (testList[j] > testList[j+1]) {
                    temp = testList[j];
                    testList[j] = testList[j+1];
                    testList[j+1] = temp;
                    swaps += 1;
                }
                comparisons += 1;
            }
        }
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        elapsed_time = end - start;

        totalComparisons += comparisons;
        totalSwaps += swaps;
        totalTime += elapsed_time.count();

        std::cout << std::left 
                  << std::setw(12) << elapsed_time.count() 
                  << std::setw(12) << comparisons 
                  << std::setw(12) << swaps << std::endl;
        fout << elapsed_time.count() << "," << comparisons << "," << swaps << std::endl; 
        delete[] testList;
    }

    // Creating sorted list
    int temp = 0;

    int* testList = new int[size]; 
    testList = copyList(aList, size);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) { //we use size - 1 - i because we don't want to iterate through already sorted items
            if (testList[j] > testList[j+1]) {
                temp = testList[j];
                testList[j] = testList[j+1];
                testList[j+1] = temp;
            }
        }
    }

    std::cout << "\n\nSorted" << std::endl;
    std::cout << std::left 
              << std::setw(12) << "Run Time" 
              << std::setw(12)<< "Comparisons"   
              << std::setw(12)<< "Swaps" << std::endl;
    fout << "\n\nSorted" << std::endl;

        for (int run = 0; run < 10; ++run) {
            long long int totalComparisons = 0;
            long long int totalSwaps = 0;
            float totalTime = 0;
            int temp = 0;
            long long int comparisons = 0;
            long long int swaps = 0;
            std::chrono::duration<float, std::milli> elapsed_time;        

            std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1 - i; j++) { //we use size - 1 - i because we don't want to iterate through already sorted items
                    if (testList[j] > testList[j+1]) {
                        temp = testList[j];
                        testList[j] = testList[j+1];
                        testList[j+1] = temp;
                        swaps += 1;
                    }
                    comparisons += 1;
                }
            }
            std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
            elapsed_time = end - start;

            totalComparisons += comparisons;
            totalSwaps += swaps;
            totalTime += elapsed_time.count();

            std::cout << std::left << std::setw(12) << elapsed_time.count() 
                        << std::setw(12) << comparisons 
                        << std::setw(12) << swaps << std::endl; 
            fout << elapsed_time.count() << "," << comparisons << "," << swaps << std::endl; 
    }
    
}

void insertionSort(int aList[], int size) { //Grabbed from https://www.geeksforgeeks.org/insertion-sort-algorithm/
    for (int i = 1; i < size; ++i) {
        int temp = aList[i];
        int j = i - 1;
        while (j >= 0 && aList[j] > temp) {
            aList[j + 1] = aList[j];
            j--;
        }
        aList[j + 1] = temp;
    }
}

void insertionSort(int aList[], int size, long long int &comparisons, long long int &swaps) { //Grabbed from https://www.geeksforgeeks.org/insertion-sort-algorithm/
    for (int i = 1; i < size; ++i) {
        int temp = aList[i];
        int j = i - 1;
        while (j >= 0 && aList[j] > temp) {
            comparisons++;
            aList[j + 1] = aList[j];
            j--;
            swaps++;
        }
        aList[j + 1] = temp;
    }
}


void dataInsertionSort(int aList[], int size, int numRuns, std::ofstream& fout) {     
    std::cout << "\n\n============INSERTION SORT=================" << std::endl;
    std::cout << "\n\nUnsorted" << std::endl;
    std::cout << std::left 
              << std::setw(12) << "Run Time" 
              << std::setw(12)<< "Comparisons"   
              << std::setw(12)<< "Swaps" << std::endl;
    

    fout << "Run Time" << ", " << "Comparisons" << ", " << "Swaps" << std::endl;
    fout << "Unsorted" << std::endl;

    for (int run = 0; run < numRuns; ++run) {
        long long int totalComparisons = 0;
        long long int totalSwaps = 0;
        float totalTime = 0;
        int temp = 0;
        long long int comparisons = 0;
        long long int swaps = 0;
        std::chrono::duration<float, std::milli> elapsed_time;

        int* testList = new int[size]; 
        testList = copyList(aList, size);
        

        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        insertionSort(testList, size, comparisons, swaps);
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        elapsed_time = end - start;

        totalComparisons += comparisons;
        totalSwaps += swaps;
        totalTime += elapsed_time.count();

        std::cout << std::left 
                  << std::setw(12) << elapsed_time.count() 
                  << std::setw(12) << comparisons 
                  << std::setw(12) << swaps << std::endl;
        fout << elapsed_time.count() << "," << comparisons << "," << swaps << std::endl;  
        delete[] testList;
    }

    // Creating sorted list
    int temp = 0;

    int* testList = new int[size]; 
    testList = copyList(aList, size);

    insertionSort(testList, size);

    std::cout << "\n\nSorted" << std::endl;
    std::cout << std::left 
              << std::setw(12) << "Run Time" 
              << std::setw(12)<< "Comparisons"   
              << std::setw(12)<< "Swaps" << std::endl;
    fout << "\n\nSorted" << std::endl;

    for (int run = 0; run < numRuns; ++run) {
        long long int totalComparisons = 0;
        long long int totalSwaps = 0;
        float totalTime = 0;
        int temp = 0;
        long long int comparisons = 0;
        long long int swaps = 0;
        std::chrono::duration<float, std::milli> elapsed_time;        

        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        insertionSort(testList, size, comparisons, swaps);
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        elapsed_time = end - start;

        totalComparisons += comparisons;
        totalSwaps += swaps;
        totalTime += elapsed_time.count();

        std::cout << std::left 
                  << std::setw(12) << elapsed_time.count() 
                  << std::setw(12) << comparisons 
                  << std::setw(12) << swaps << std::endl;
        fout << elapsed_time.count() << "," << comparisons << "," << swaps << std::endl;  
    }

}

void merge(int aList[], int begin, int mid, int end, long long int& comparisons, long long int& swaps) {
    int i,
        j,
        k;

    // Determine size for subarrays
    int sizeLeft = mid - begin + 1;
    int sizeRight = end - mid;

    // Temporary arrays
    int* left = new int[sizeLeft];
    int* right = new int[sizeRight];

    // Copy into temps
    for (i = 0; i < sizeLeft; i++) {
        left[i] = aList[begin + i];
    }
    for (j = 0; j < sizeRight; j++) {
        right[j] = aList[mid + 1 + j];
    }

    // Merge
    i = 0;
    j = 0;
    k = begin;

    while (i < sizeLeft && j < sizeRight) {
        comparisons += 1;
        if (left[i] <= right[j]) {
            aList[k] = left[i];
            i++;
        }
        else {
            aList[k] = right[j];
            j++;
        }
        swaps += 1;
        k++;
    }

    while (i < sizeLeft) {
        aList[k] = left[i];
        i++;
        k++;
        swaps += 1;
    }

    while (j < sizeRight) {
        aList[k] = right[j];
        j++;
        k++;
        swaps += 1;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int aList[], int left, int right, long long int& comparisons, long long int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(aList, left, mid, comparisons, swaps);
        mergeSort(aList, mid + 1, right, comparisons, swaps);

        merge(aList, left, mid, right, comparisons, swaps);
    }
}

void dataMergeSort(int aList[], int size, int numRuns, std::ofstream& fout) {     
    std::cout << "\n\n============MERGE SORT=================" << std::endl;
    std::cout << "\n\nUnsorted" << std::endl;
    std::cout << std::left 
              << std::setw(12) << "Run Time" 
              << std::setw(12)<< "Comparisons"   
              << std::setw(12)<< "Swaps" << std::endl;
    

    fout << "Run Time" << ", " << "Comparisons" << ", " << "Swaps" << std::endl;
    fout << "Unsorted" << std::endl;

    for (int run = 0; run < numRuns; ++run) {
        long long int totalComparisons = 0;
        long long int totalSwaps = 0;
        float totalTime = 0;
        int temp = 0;
        long long int comparisons = 0;
        long long int swaps = 0;
        std::chrono::duration<float, std::milli> elapsed_time;

        int* testList = new int[size]; 
        testList = copyList(aList, size);
        

        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        mergeSort(testList, 0, size-1, comparisons, swaps);
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        elapsed_time = end - start;

        totalComparisons += comparisons;
        totalSwaps += swaps;
        totalTime += elapsed_time.count();

        std::cout << std::left 
                  << std::setw(12) << elapsed_time.count() 
                  << std::setw(12) << comparisons 
                  << std::setw(12) << swaps << std::endl;
        fout << elapsed_time.count() << "," << comparisons << "," << swaps << std::endl;  
        delete[] testList;
    }

    // Creating sorted list
    int temp = 0;

    int* testList = new int[size]; 
    testList = copyList(aList, size);

    insertionSort(testList, size);

    std::cout << "\n\nSorted" << std::endl;
    std::cout << std::left 
              << std::setw(12) << "Run Time" 
              << std::setw(12)<< "Comparisons"   
              << std::setw(12)<< "Swaps" << std::endl;
    fout << "\n\nSorted" << std::endl;

    for (int run = 0; run < numRuns; ++run) {
        long long int totalComparisons = 0;
        long long int totalSwaps = 0;
        float totalTime = 0;
        int temp = 0;
        long long int comparisons = 0;
        long long int swaps = 0;
        std::chrono::duration<float, std::milli> elapsed_time;        

        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        mergeSort(testList, 0, size-1, comparisons, swaps);
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        elapsed_time = end - start;

        totalComparisons += comparisons;
        totalSwaps += swaps;
        totalTime += elapsed_time.count();

        std::cout << std::left 
                  << std::setw(12) << elapsed_time.count() 
                  << std::setw(12) << comparisons 
                  << std::setw(12) << swaps << std::endl;
        fout << elapsed_time.count() << "," << comparisons << "," << swaps << std::endl;  
    }

}