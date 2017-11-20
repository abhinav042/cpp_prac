#include <iostream>

using namespace std;

template <class T> 
class queue {
    struct node {
        T data;
        node* next;
    };
    node* top, *tail;
    public:
        queue() {
			top = nullptr;
			tail = nullptr;
		}

		void push(T item) {
			node* new_node = new node();
			new_node->data = item;
			new_node->next = nullptr;
			if (top == nullptr && tail == nullptr) {
				top = new_node;
				top->next = tail;
				tail = new_node;
			} else {
				tail->next = new_node;
				tail = new_node;
			}
		}

		T pop() {
			node* new_node = new node();
			new_node = top;
			top = top->next;
			T item = new_node->data;
			delete new_node;
			return item;
		}

		void print() {
			node* new_node = new node();
			new_node = top;
			while(new_node!=nullptr) {
				cout << new_node->data << " ";
				new_node = new_node->next;
			}
			cout << endl;
		}
		
};

int main() {
	queue<int> my_queue;
	my_queue.push(1);
	my_queue.push(2);
	my_queue.push(3);
	my_queue.push(4);
	my_queue.print();
	my_queue.pop();
	my_queue.print();
	my_queue.pop();
	my_queue.print();
	my_queue.push(1);
	my_queue.push(2);
	my_queue.push(3);
	my_queue.push(4);
	my_queue.print();
	return 0;
}
