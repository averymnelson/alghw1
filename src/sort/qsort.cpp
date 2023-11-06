#include <sort.hpp>
#include <graph.hpp>

// extern
std::string sortAlgName = "Quick Sort";

template <class T>
void heapify(std::vector<T> &arr, int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

template <class T>
void sort(std::vector<T> &array, int l, int r)
{
    int N = array.size();
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(array, N, i);

    // One by one extract an element from heap
    for (int i = N - 1; i > 0; i--)
    {

        // Move current root to end
        std::swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

template void sort(std::vector<Edge> &array, int l, int r);
template void sort(std::vector<int> &array, int l, int r);
