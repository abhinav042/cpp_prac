#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ALPHABET_SIZE 26

using namespace std;

struct Trie_node {
    // assuming we can only have the english alphabets
    // assuming case insensitivity
    unordered_map <char, Trie_node> children;
    bool is_end_of_word;
    int num_of_child;
}

struct Trie_node* get_node () {
    
}


int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            add(contact);
        } else if (op == "find") {
            find(contact);
        }
    }
    return 0;
}
