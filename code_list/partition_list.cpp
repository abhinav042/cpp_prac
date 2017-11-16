#include <iostream>
#include <list>

using namespace std;

void print(list <int> linked_list, list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main() {
    list <int> linked_list({2,8,7,5,3,1,4});
    list <int> copy_list;
    list <int>::iterator itr;
    int val;
    print(linked_list, itr);
    cout << "enter the val : ";
    cin >> val;
    for (itr = linked_list.begin(); itr != linked_list.end(); ++itr) {
        if (val > *itr)
            copy_list.push_front(*itr);
        else
            copy_list.push_back(*itr);
    }
    print(copy_list, itr);
    return 0;
}