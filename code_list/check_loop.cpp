#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void print(list <int> linked_list, list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main() {
    list <int> linked_list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    list <int>::iterator itr;
    itr = linked_list.end();
    linked_list.begin() = itr;
    if (linked_list.end() == linked_list.begin()) cout << "it works" << endl;
    else cout << "it doesnt";
    print(linked_list, itr);
    cout << "under construction";
    return 0;
}