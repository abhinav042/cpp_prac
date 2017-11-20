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
        T pop() {
            node* del_ptr = new node();
            if (top == nullptr) {
                cout << endl << "STACK_UNDERFLOW" << endl;
                return -1;
            }
            del_ptr = top;
            top = top->next;
            int old_top = del_ptr->data;
            delete del_ptr;
            return old_top;
        }
        void print() {
            node* ptr = new node();
            ptr = top;
            while(ptr!=nullptr) {
                cout << (*ptr).data << " ";
                ptr = (*ptr).next;
            }
            cout << endl;
        }
};

int main() {
    stack<int> issa_stack;

    issa_stack.push(1);
    issa_stack.push(2);
    issa_stack.push(3);
    issa_stack.print();
    issa_stack.pop();
    issa_stack.pop();
    issa_stack.pop();
    issa_stack.pop();
    issa_stack.print();
    return 0;
}