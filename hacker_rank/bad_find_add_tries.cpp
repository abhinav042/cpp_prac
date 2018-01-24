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
    int num_of_words;
    
    Trie_node() {
        is_end_of_word = false;
        num_of_words = 0;
    }

    Trie_node get_node (char c) {
        return children[c];
    }

    void set_node(char c, Trie_node node) {
        children[c] = node;
    }

    void add(string word, int index = 0) {
        num_of_words++;
        if (index == word.length()) {
            is_end_of_word = true;
            return;
        }
        char curr_letter = word[index];
        if (children.find(curr_letter) == children.end()) {
            Trie_node* node = new Trie_node();
            set_node(curr_letter, node);
        }
        node.add(word, index++);
    }

    int find(string word, int index = 0) {
        if (index == word.length()) {
            return num_of_words;
        }
        char curr_letter = word[index];
        if (children.find(curr_letter) == children.end()) {
            return 0;
        } else {
            Trie_node node = new Trie_node();
            set_node(word[index], c)
        }
    }
};

int main(){
    int n;
    cin >> n;
    Trie_node root;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            root.add(contact);
        } else if (op == "find") {
            cout << root.find(contact) << endl;
        }
    }
    return 0;
}
