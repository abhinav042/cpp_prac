#include <iostream>
#include <string>
#include <list>

using namespace std;

void print(list <char> linked_list, list<char>::iterator itr) {
    for (itr= linked_list.begin(); itr!= linked_list.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
}

bool check_palin(list <char> linked_list) {
    list<char>::iterator itrBegin;
    list<char>::iterator itrEnd;
    for (itrBegin = linked_list.begin(), itrEnd = prev(linked_list.end()); itrBegin!=itrEnd; ++itrBegin, --itrEnd) {
        if (*itrBegin != *itrEnd) {
            return false;
        }
    }
    return true;
}

int main() {
    list <char> linked_list({'r','a','c','e','c','a','r'});
    list <char>::iterator itr;
    
    print(linked_list, itr);
    if (check_palin(linked_list))
        cout << "is palin" << endl;
    else
        cout << "is not palin";
    return 0;
}