#include <iostream>

using namespace std;

// implement a stack

template <class T>
class stack {
    struct node {
        T data;
        node* next;
    };
    node* top;
    public:
        stack() {
            top = nullptr;
        }
        void push(T item) {
            node* new_node = new node();
            new_node->data = item;
            new_node->next = top;
            top = new_node;
        }
        // pop();
        void print() {
            cout << top->data << endl;
            node* ptr = new node();
            ptr = top;
            cout << ptr->data << endl;
            while(ptr!=nullptr) {
                cout << (*ptr).data << " ";
                ptr = (*ptr).next;
            }
        }
};

int main() {
    stack<int> issa_stack;

    issa_stack.push(1);
    issa_stack.push(2);
    issa_stack.print();
    return 0;
}