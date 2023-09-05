template<class T>
struct StackNode {
 T value;
 StackNode<T> *next;
 StackNode<T> *prev;
 StackNode(T value, StackNode<T> *next, StackNode <T> *prev);
6
 ~StackNode();
};
template<class T>
class Stack {
 private:
 StackNode<T> *head;
 StackNode<T> *tail;
 public:
 Stack();
 ~Stack();
 bool empty();
 T pop();
 void push(T value);
};
