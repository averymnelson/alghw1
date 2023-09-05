#include "stack.hpp"

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
