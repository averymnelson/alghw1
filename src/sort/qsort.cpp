#include <sort.hpp>
#include <graph.hpp>

// extern
std::string sortAlgName = "Quick Sort";

template <typename T>
int partition(std::vector<T> &arr, int start, int end)
{
 
    T pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start;
    int j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 

template <class T>
void sort(std::vector<T> &array, int l, int r)
{
    
    // base case
    if (l >= r)
        return;
 
    // partitioning the array
    int p = partition(array, l, r);
 
    // Sorting the left part
    sort(array, l, p - 1);
 
    // Sorting the right part
    sort(array, p + 1, r);
    }
// YOUR CODE HERE
// Sorray array from l to r, i.e. sort array[l...r]

template void sort(std::vector<Edge> &array, int l, int r);
template void sort(std::vector<int> &array, int l, int r);
