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
      StackNode *Temp = head;
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
    StackNode *p = head;
    head = head->next;
    delete p;
    return value;
}

template<class T>
void Stack<T>::push(T value) {
    StackNode<T> *p = new StackNode<T>(value, NULL, NULL);
    if (p == NULL){
        return;
    }
    p->value = value;
    p->next = head;
    head = p;
}

template class Stack<int>;
