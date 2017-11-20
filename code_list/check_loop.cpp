#include <iostream>
#include <list>
#include <iterator>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void print(list <int> linked_list, list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    
    if (head == nullptr) {
        return false;
    }
    
    Node* slow_ptr = new Node();
    Node* fast_ptr = new Node();
    
    slow_ptr = head;
    fast_ptr = head;
    
    while(fast_ptr!=nullptr && fast_ptr->next!=nullptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = (fast_ptr->next)->next;
        if (slow_ptr == fast_ptr) {
            return true;
        }
    }
    
    return false;
    
}

int main() {
    // handled via the buffer
    return 0;
}