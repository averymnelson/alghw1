#include <sort.hpp>
#include <graph.hpp> 

std::string sortAlgName = "Merge Sort";

template<class T>
void merge(std::vector<T> &array, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    auto *leftArray = new T[subArrayOne], 
        *rightArray = new T[subArrayTwo];
 
    for (int i = 0; i < subArrayOne; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
    }
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (l >= r){
        return;
    }
    int mid = l + (r - l) / 2;
    sort(array, l, mid);
    sort(array, mid + 1, r);
    merge(array, l, mid, r);    
}
template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);