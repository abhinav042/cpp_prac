#include <iostream>
#include <forward_list>

using namespace std;

void print(forward_list <int> linked_list, forward_list<int>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << endl;
    }
    cout << endl;
}

int main() {
    int k;
    forward_list <int> single_list;
    forward_list <int>::iterator itr;
    for (int i = 0; i < 10; i++) {
        single_list.push_front(i);
    }
    print (single_list, itr);
    cout << "enter the val of k : ";
    cin >> k;
    int length = 0;
    for (itr=single_list.begin(); itr!=single_list.end(); ++itr) {
        length++;
    }
    cout << "length is : " << length << endl;
    if (k < length) {
        int i = 0;
        bool flag = false;
        for (itr = single_list.begin(); itr!=single_list.end(); ++itr) {
            if (i == length-k || flag==true) {
                flag = true;
                cout << *itr;
            }
            i++;
        }
    }
}