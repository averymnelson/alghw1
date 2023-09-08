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
    // YOUR CODE HERE
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
 // code to insert at head or tail depending on answer
 // node by search value
 // add to node?
    LinkedListNode *ptr = new LinkedListNode(value);
    ptr->root;
    root = ptr;
}
template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
 // DFS
 // return node
 //Walk the linked list
 LinkedListNode *curr = root; 
 while((curr!=NULL) && (curr->value != value)){
    curr = curr->value;
    //If result is found
    if(curr->value == value){
        cout << "Value found\n";
        cout << *curr;
        return LinkedListNode;
    }
 }
 //No results found
 if(curr == NULL){
    cout << "No results found\n"
    return;
 }

}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    // YOUR CODE HERE
    //Walk the list until matching value found
    find(value);
    LinkedListNode *tmp = root;
    delete tmp;

}

template<class T>
int LinkedList<T>::size() {
 // traverse list, keep counter variable.
}

template class LinkedListNode<int>;
template class LinkedList<int>;
