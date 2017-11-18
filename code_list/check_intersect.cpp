#include <iostream>
#include <forward_list>

using namespace std;

void print(forward_list <int> linked_list, forward_list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

bool return_linked_list (forward_list <int> linked_list1, forward_list<int>::iterator itr1, forward_list <int> linked_list2, forward_list<int>::iterator itr2) {
    for (itr1 = linked_list1.begin(), itr2 = linked_list2.begin(); itr1!=linked_list1.end(), itr2!=linked_list2.end();++itr1, ++itr2) {
        if (itr1 == itr2) {
            cout << "the value of the collision point is : " << *itr1 << endl;
            return true;
        }
    }
    return false;
}

int main() {
    forward_list <int> linked_list1;
    forward_list <int> linked_list2;
    forward_list <int>::iterator itr;
    forward_list <int>::iterator itr1;
    forward_list <int>::iterator itr2;
    // int len, length1 = 0, length2 = 0;
    
    // for (itr1 = linked_list1.begin(); itr1!=linked_list.end(); ++itr1) {
    //     length1++;
    // }

    // for (itr2 = linked_list.begin(); itr2!=linked_list.end(); ++itr2) {
    //     length2++;
    // }

    if (return_linked_list(linked_list1, itr1, linked_list2, itr2)) {
        cout << "yep, collision" << endl;
    } else {
        cout << "nope" << endl;
    }

    return 0;
}