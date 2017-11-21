#include <iostream>

using namespace std;

template <class T>
class mystack {

    struct node {
        T data;
        T MIN_VAL;
        node* next;
    } *top;
    
    public:
        mystack() {
            top = nullptr;
        }
        void push(T item) {
            node* new_ptr = new node();
            new_ptr->data = item;
            new_ptr->next = nullptr;
            if (top == nullptr) {
                top = new_ptr;
                top->MIN_VAL = top->data;
            } else {
                new_ptr->next = top;
                if (top->MIN_VAL > new_ptr->data)
                    new_ptr->MIN_VAL = new_ptr->data;
                else {
                    new_ptr->MIN_VAL = top->MIN_VAL;
                }
                top = new_ptr;
            }
        }
        T pop() {
            T item;
            node* new_ptr = new node();
            new_ptr = top;
            top = top->next;
            item = new_ptr->data;
            delete new_ptr;
            return item;
        }
        T peep() {
            return top->MIN_VAL;
        }
};

int main() {
    mystack<int> min_stack;
    min_stack.push(1);
    min_stack.push(2);
    min_stack.push(3);
    min_stack.push(4);
    min_stack.push(5);
    cout << min_stack.peep() << endl;
    min_stack.pop();
    cout << min_stack.peep() << endl;
    min_stack.push(0);
    min_stack.push(3);
    min_stack.push(-1);
    cout << min_stack.peep() << endl;
    return 0;
}