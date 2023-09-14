#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    //create node pointer to the root
    LinkedListNode<T>* ptr = this->root;
    //walk the list while the pointer is not null
    while(ptr != NULL){
        //create a temporary pointer to the next value
        LinkedListNode<T>* temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    //create node pointer to the root
    LinkedListNode<T>* ptr = this->root;
    //Walk the list while pointer is not null
    while(ptr != NULL){
        //value is found in the list
        if(ptr->value == value)
            return ptr;
        ptr = ptr->next;
    }
    //create a new node to insert
    LinkedListNode<T> *node = new LinkedListNode<T>();
    node->value = value;
    //inserting at the head of the list
    node->next = this->root;
    this->root = node;
    return this->root;
}


template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
 //create node pointer to the root
 LinkedListNode<T> *curr = this->root;
 while(curr != NULL){
    //value is found in the list
    if(curr->value == value) break;
    curr = curr->next;
 }
 return curr;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    //create node pointer to the root and curr pointer to move along the list
    LinkedListNode<T>* ptr = this->root;
    LinkedListNode<T>* curr = NULL;
    while(ptr != NULL){
        if(ptr->value == value){
            if(curr == NULL)
                this->root = ptr->next;
            else
                curr->next = ptr->next;
            delete ptr;
            break;
        }
        curr = ptr;
        ptr = ptr->next;
    }
    return this->root;
}

template<class T>
int LinkedList<T>::size() {
 // traverse list, keep counter variable.
    LinkedListNode<T>* ptr = this->root;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

template class LinkedListNode<int>;
template class LinkedList<int>;
