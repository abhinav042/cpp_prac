#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int array;
    int index;
    int value;

    Node(int, int, int);
};

Node::Node(int array, int index, int value) {
    this->array = array;
    this->index = index;
    this->value = value;
}

bool operator< (const Node& node1, const Node& node2) {
    return node1.value < node2.value;
}

int* merge(vector < vector <int> > input) {
    priority_queue<Node*, vector<Node>, less<vector<Node>::value_type> > pq;
    int total_elem = 0;
    for (int i = 0; i < input.size(); i++) {
        total_elem += input[i].size();
    }
    return nullptr;
}

int main() {
    // take input
    int num_arrays;
    int max_size;
    int total_elem;
    vector <vector <int> > input;
    return 0;
}