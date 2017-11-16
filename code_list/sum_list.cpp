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
    list <int> linked_list1({7, 1, 6});
    list <int> linked_list2({5, 9, 4});
    list <int> result;
    list <int>::iterator itr1;
    list <int>::iterator itr2;
    int carry_over = 0;
    int val = 0;
    for (itr1 = linked_list1.begin(), itr2 = linked_list2.begin(); itr1 != linked_list1.end() || itr2 != linked_list2.end(); ++itr1, ++itr2) {
        val = *itr1 + *itr2 + carry_over;
        result.push_front(val%10);
        carry_over = val/10;
        if (carry_over!=0 && next(itr1) == linked_list1.end()) 
            result.push_front(carry_over);
    }
    print (result, itr1);
    return 0;
}