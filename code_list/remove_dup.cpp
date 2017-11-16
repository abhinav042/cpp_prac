#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(list <int> linked_list, list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << endl;
    }
}

int main() {
    list <int> linked_list;
    unordered_map <int, int> hashmap;
    list <int>::iterator itr;
    // creating a linked_list with duplicates
    for (int i = 0; i < 10; i++) {
        linked_list.push_back(i);
        linked_list.push_back(i+1);
    }
    // display
    print(linked_list, itr);
    cout << endl;
    for (itr = linked_list.begin(); itr != linked_list.end(); ++itr) {
        if (hashmap[*itr])
            linked_list.erase(itr);
        else 
            hashmap[*itr]++;
    }
    // linked_list.unique();
    print(linked_list, itr);
    return 0;
}