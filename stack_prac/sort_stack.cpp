#include <iostream>
#include <stack>
#include <iterator> 

using namespace std;

void sort(stack<int>& mystack) {
    stack <int> temp_stack;
    int temp_int;
    while(!mystack.empty()) {
        temp_int = mystack.top();
        cout << "temp_int is : " << temp_int << endl;
        mystack.pop();
        while (!temp_stack.empty() && temp_int < temp_stack.top()) {
            mystack.push(temp_stack.top());
            temp_stack.pop();
        }
        temp_stack.push(temp_int);
    }
    // copy back to mystack
    while (!temp_stack.empty()) {
        mystack.push(temp_stack.top());
        temp_stack.pop();
    }
}

int main() {
    cout << "start" << endl;
    stack <int> issa_stack;
    issa_stack.push(1);
    issa_stack.push(3);
    issa_stack.push(2);
    issa_stack.push(5);
    // issa_stack.push(1);
    // issa_stack.push(324);
    // issa_stack.push(123);
    issa_stack.push(0);
    issa_stack.push(2);
    issa_stack.push(5);
    sort(issa_stack);
    cout << "top is : " << issa_stack.top() << endl;
    issa_stack.pop();
    cout << "top is : " << issa_stack.top() << endl;
    issa_stack.pop();
    cout << "top is : " << issa_stack.top() << endl;
    issa_stack.pop();
    cout << "top is : " << issa_stack.top() << endl;
    return 0;
}