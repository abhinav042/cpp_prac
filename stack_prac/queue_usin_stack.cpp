#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue {
    stack<T>new_elem_stack;
    stack<T>old_elem_stack;
    
    public:
    
    void push(T item) {
        new_elem_stack.push(item);
    }

    T pop() {
        if (new_elem_stack.size() + old_elem_stack.size() == 0) {
            cout << "QUEUE_UNDERFLOW" << endl;
        }
        if (new_old_stack.empty()) {
            while(!new_elem_stack.empty()) {
                old_elem_stack.push(new_elem_stack.top());
                new_elem_stack.pop();
            }
        }
        T item = old_elem_stack.top();
        old_elem_stack.pop();
        return item;
    }

    T peep() {
        if (new_elem_stack.size() + old_elem_stack.size() == 0) {
            cout << "QUEUE_UNDERFLOW" << endl;
        }
        if (new_old_stack.empty()) {
            while(!new_elem_stack.empty()) {
                old_elem_stack.push(new_elem_stack.top());
                new_elem_stack.pop();
            }
        }
        return old_elem_stack.top();;
    }
};

int main() {
    MyQueue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);
    my_queue.push(4);
    my_queue.push(5);
    my_queue.push(6);
    cout << my_queue.pop() << endl;
    cout << my_queue.peep() << endl;
    cout << my_queue.pop() << endl;
    cout << my_queue.peep() << endl;
    return 0;
}