#include <sort.hpp>
#include <graph.hpp>

std::string sortAlgName = "Quick Sort";
template<class T>
int partition(std::vector<T> &arr, int start, int end)
{
    T pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
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
    if (l >= r){
        return;
    }
    int p = partition(array, l, r); 
    sort(array, l, p - 1);
    sort(array, p + 1, r);
}
template void sort(std::vector<Edge> &array, int l, int r);
template void sort(std::vector<int> &array, int l, int r);