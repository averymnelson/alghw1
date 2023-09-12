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
    //p is the root of the linked list
    //while p is not a NULL

    LinkedListNode<T>* ptr = this->root;
    while(ptr != NULL){
        LinkedListNode<T>* temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
 // code to insert at head or tail depending on answer
 // node by search value
 // add to node?
    LinkedListNode<T>* ptr = this->root;
    while(ptr != NULL){
        if(ptr->value == value)
            return ptr;
        ptr = ptr->next;
    }

    LinkedListNode<T> *node = new LinkedListNode<T>();
    node->value = value;
    node->next = this->root;
    this->root = node;
    return this->root;
}


template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
 // DFS
 // return node
 //Walk the linked list
 LinkedListNode<T> *curr = this->root;
 while(curr!=NULL){
    //curr = curr->value;
    //If result is found
    if(curr->value == value){
        std::cout << "Value found\n";
        std::cout << *curr;
        break;
        //return curr;
    }
 }
 return curr;
 //No results found
 if(curr == NULL){
    std::cout << "Null node\n"<<std::endl;
    return;
 }

}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    // YOUR CODE HERE
    //Walk the list until matching value found
    //find(value);
    //LinkedListNode *tmp = root;
    //delete tmp;
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
