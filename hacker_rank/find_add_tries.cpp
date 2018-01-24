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
    Trie_node* children[ALPHABET_SIZE];
    bool is_word;
    int num_words;
};

Trie_node* get_node() {
    Trie_node* node = new Trie_node;
    node->is_word = false;
    node->num_words = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = nullptr;
    }
    return node;
}

void insert(string word, Trie_node* node, int index = 0) {
    node->num_words += 1;
    if (index == word.length() - 1) {
        node->is_word = true;
        return;
    }
    char current_char = word[index];
    if (node->children[current_char - 'a'] != nullptr) {
        insert(word, node->children[current_char - 'a'], index + 1);
    } else {
        Trie_node* new_node = get_node();
        node->children[current_char - 'a'] = new_node;
        // cout << node->children[current_char - 'a'] << endl;
        insert(word, new_node, index + 1);
    }
}

void find_num_words(string word, Trie_node* node) {
    Trie_node *temp = node;
    // if (index == word.length() - 1) {
    //     return node->num_words;
    // } 
    // if (node->children[word[index]] == nullptr) {
    //     return 0;
    // }
    // find_num_words(word, node->children[word[index]], index + 1);
    for (int i = 0; i < word.length() - 1; i++) {
        if (node->children[word[i] - 'a'] == nullptr) {
            // cout << "i get run.." << endl;
            return 0;
        }
        // cout << node->children[word[i] - 'a'] << endl;
    }
    cout << node->num_words << endl;
    // return node->num_words;
}

int main(){
    int n;
    cin >> n;
    Trie_node* root = get_node();
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            insert(contact, root);
        } else if (op == "find") {
            // cout << find_num_words(contact, root) << endl;
            find_num_words(contact, root);
        }
    }
    return 0;
}