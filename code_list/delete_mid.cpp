#include <iostream>
#include <iterator>
#include <forward_list>
// not using algorithm header
using namespace std;

void print(forward_list <int> linked_list, forward_list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << endl;
    }
    cout << endl;
}

int main() {
    forward_list <int> single_list;
    forward_list <int>::iterator itr;
    int val;
    for (int i = 0; i < 10; i++) {
        single_list.push_front(i);
    }
    cout << "enter the val of node : ";
    cin >> val;
    
    for (itr=single_list.begin(); itr!=single_list.end(); ++itr) {
        if (next(itr) == single_list.end()) break;
        if (*next(itr) == val) {
            single_list.erase_after(itr);
        }
    }
    print(single_list, itr);
}

