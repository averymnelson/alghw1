void pointers(){
int x =5;
int *p=&x;
int k = *p;
printf("%d\n",p);
printf("%d\n",*p);
printf("%d\n",&p);
}

template <typename Type>
Type sqr( Type x ) {
 return x*x;
}
class underflow {
 // empty
};

class Node {
 public:
 Node( int = 0, Node * = nullptr );
 int value() const;
 Node *next() const;
 private:
 int node_value;
 Node *next_node;
};

int List::Node::value() const {
 return node_value;
}

List::Node *List::Node::next() const {
 return next_node;
}

bool List::empty() const {
 return ( list_head == nullptr );
}

List::Node *List::begin() const {
 return list_head;
}

int List::front() const {
 if ( empty() ) {
 throw underflow();
 }
 return begin()->value();
}

void List::push_front( int n ) {
if ( empty() ) {
 list_head = new Node( n, nullptr );
 } else {
 list_head = new Node( n, begin() );
 }
}

int List::pop_front() {
 if ( empty() ) {
 throw underflow();
 }
 int e = front();
 Node *ptr = list_head;
 list_head = list_head->next();
 delete ptr;
 return e;
}

int List::count( int n ) const {
 int node_count = 0;
 for ( Node *ptr = begin(); ptr != end(); ptr = ptr->next() ) {
 if ( ptr->value() == n ) {
 ++node_count;
 }
 }
 return node_count;
}



int main() {

 cout << "3 squared is " << sqr<int>( 3 ) << endl;
 cout << "Pi squared is " << sqr<double>( 3.141592653589793 ) << endl;
 return 0;

}