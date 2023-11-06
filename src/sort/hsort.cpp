#include <sort.hpp>
#include <graph.hpp> 

std::string sortAlgName = "Heap Sort";

template<class T>
void heapify(std::vector<T> &arr, int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest]){
        largest = l;
    }
    if (r < N && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    int N = array.size();
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(array, N, i);
    }
    for (int i = N - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);