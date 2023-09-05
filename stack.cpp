#include "stack.hpp"

// #include <stack.hpp>

// template<class T>
// StackNode<T>::StackNode(T value, StackNode<T> *next, StackNode<T> *prev) {
//     this->value = value;
//     this->next = next;
//     this->prev = prev;
// }

// template<class T>
// StackNode<T>::~StackNode() {
//     this->next = this->prev = NULL;
// }

// template<class T>
// Stack<T>::Stack() {
//     this->head = this->tail = NULL;
// }

// template<class T>
// Stack<T>::~Stack() {
//     // YOUR CODE HERE 
// }

// template<class T>
// bool Stack<T>::empty() {
//     // YOUR CODE HERE
//     return true;
// }

// template<class T>
// T Stack<T>::pop() {
//     T value = this->head->value;
//     // YOUR CODE HERE
//     return value;
// }

// template<class T>
// void Stack<T>::push(T value) {
//     StackNode<T> *p = new StackNode<T>(value, NULL, NULL);
//     // YOUR CODE HERE
// }

// template class Stack<int>;


template<class T>
Stack<T>::~Stack() {
 // YOUR CODE HERE
}
template<class T>
bool Stack<T>::empty() {
 // YOUR CODE HERE
7
}
template<class T>
T Stack<T>::pop() {
 T value = this->tail->value;
 // YOUR CODE HERE
 return value;
}
template<class T>
void Stack<T>::push(T value) {
 StackNode<T> *p = new StackNode<T>(value, NULL, NULL);
 // YOUR CODE HERE
}
