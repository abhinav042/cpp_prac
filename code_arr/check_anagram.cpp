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

using namespace std;

int number_needed(string a, string b) {
    vector<int> freq(26, 0);
    
    int count = 0;
    
    for (int i = 0; i < a.length(); i++) {
        ++freq[a[i]-'a'];
    }
    
    for (int i = 0; i < b.length(); i++) {
        --freq[b[i]-'a'];
    }
    
    for (int i = 0; i < 26; i++) {
        if (freq[i]!=0) count = count + abs(freq[i]);
    }
    
    return count;
    
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
