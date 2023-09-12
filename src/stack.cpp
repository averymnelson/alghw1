#include <stack.hpp>

template<class T>
StackNode<T>::StackNode(T value, StackNode<T> *next, StackNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
StackNode<T>::~StackNode() {
    this->next = this->prev = NULL;
}

template<class T>
Stack<T>::Stack() {
    this->head = this->tail = NULL;
}

template<class T>
Stack<T>::~Stack() {
    while (head != NULL)
   {
      StackNode<T> *Temp = head;
      head = head->next;
      delete Temp;
   }

   head = NULL;
}

template<class T>
bool Stack<T>::empty() {
    return (Stack().empty());
}

template<class T>
T Stack<T>::pop() {
    T value = this->head->value;
    StackNode<T> *p = this->tail;
    this->tail = this->tail->prev;
    if (this->tail == NULL){
        this->head = this->tail = NULL;
    }else{
        this->tail->next = NULL;
    }
    delete p;
    return value;
}

template<class T>
void Stack<T>::push(T value) {
    StackNode<T> *temp = new StackNode<T>(value, NULL, NULL);
    if (this->tail == NULL){
        this->head = this->tail = temp;
    }else{
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }

}

template class Stack<int>;